#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <assert.h>

// Copyright (c) 2015
// Author: Chrono Law
#include <iostream>
using namespace std;

#define BOOST_THREAD_VERSION 4
#include <boost/ref.hpp>
#include <boost/thread.hpp>
using namespace boost;




//////////////////////////////////////////

#include <boost/chrono.hpp>
using namespace boost::chrono;
seconds operator"" _s(unsigned long long n)
{
    return seconds(n);
}

milliseconds operator"" _ms(unsigned long long n)
{
    return milliseconds(n);
}
//////////////////////////////////////////

void case1()
{
	boost::mutex mu;
    try
    {
        mu.lock();
        cout  << "some operations" << endl;
        mu.unlock();
    }
    catch (...)
    {
        mu.unlock();
    }

    {
		boost::lock_guard<boost::mutex> g(mu);
        cout  << "some operations" << endl;
    }
}

//////////////////////////////////////////
void case2()
{
	boost::timed_mutex mu;

    auto flag = mu.try_lock_for(100_ms);
    if(flag)
    {
        cout << "lock timed mutex" << endl;
        mu.unlock();
    }

    {
        if(mu.try_lock_for(100_ms))
        {
			boost::lock_guard<boost::timed_mutex> g(mu, boost::adopt_lock);
            cout << "lock timed mutex" << endl;
        }
    }
}

//////////////////////////////////////////
#include <boost/thread/lock_factories.hpp>

template <typename Lockable, typename D>
boost::unique_lock<Lockable> my_make_lock(Lockable& mtx, D d)
{
    return boost::unique_lock<Lockable> (mtx, d);
}

void case3()
{
	boost::mutex mu;

    {
        auto g = make_unique_lock(mu);
        assert(g.owns_lock());
        cout  << "some operations" << endl;
    }

    {
        auto g = make_unique_lock(mu, boost::defer_lock);
        assert(!g);

        assert(g.try_lock());
        assert(g);

        cout  << "some operations" << endl;
    }

	boost::timed_mutex tm;
    //typedef unique_lock<timed_mutex> lock_type;

    {
        //lock_type g(tm, 100_ms);
        auto g = my_make_lock(tm, 100_ms);
        if(g)
        {
            cout << "lock timed mutex" << endl;
        }
    }

    auto g = make_unique_locks(mu, tm);
	assert(std::tuple_size<decltype(g)>::value == 2);
}

//////////////////////////////////////////
#include <boost/atomic.hpp>
#include <boost/thread/lockable_adapter.hpp>
class account final : public lockable_adapter<boost::mutex>
{
private:
	boost::atomics::atomic<int> m_money{0};
public:
    account() {}
    ~account() {}
public:
    int sum() const
    {
        return m_money;
    }

    void withdraw(int x)
    {
        m_money -= x;
    }

    void deposit(int x)
    {
        m_money += x;
    }
};

void case4()
{
    account a;

    {
        auto g = make_unique_lock(a);
        a.deposit(100);
        a.withdraw(20);
        assert(a.sum() == 80);
    }

    {
        auto b = make_unique_lock(a, boost::try_to_lock);
        if(b)
        {
            a.withdraw(a.sum());
            assert(a.sum() == 0);
        }
    }
}

//////////////////////////////////////////
void case5()
{
	boost::mutex m1, m2;

    {
        auto g1 = make_unique_lock(m1, boost::adopt_lock);
        auto g2 = make_unique_lock(m2, boost::adopt_lock);

        lock(m1, m2);
    }

    {
        auto g1 = make_unique_lock(m1, boost::defer_lock);
        auto g2 = make_unique_lock(m2, boost::defer_lock);

        try_lock(g1, g2);
    }
}

//////////////////////////////////////////
#include <boost/thread/lockable_concepts.hpp>
void case6()
{
    BOOST_CONCEPT_ASSERT((BasicLockable<boost::mutex>));
    BOOST_CONCEPT_ASSERT((Lockable<boost::mutex>));

    BOOST_CONCEPT_ASSERT((Lockable<boost::timed_mutex>));
    BOOST_CONCEPT_ASSERT((TimedLockable<boost::timed_mutex>));

    BOOST_CONCEPT_ASSERT((Lockable<account>));
    BOOST_CONCEPT_ASSERT((Lockable<lockable_adapter<boost::mutex>>));

    //BOOST_CONCEPT_ASSERT((Lockable<boost::atomics::atomic<int>>));
}

//////////////////////////////////////////
#include <boost/thread/shared_lock_guard.hpp>
class rw_data
{
    private:
        int m_x;
        shared_mutex rw_mu;
    public:
        rw_data():m_x(0){}
        void write()
        {
			boost::unique_lock<shared_mutex> g(rw_mu);
            ++m_x;
        }
        void read(int *x)
        {
            //shared_lock_guard<shared_mutex> g(rw_mu);
            shared_lock<shared_mutex> g(rw_mu);
            *x = m_x;
        }
};

void writer(rw_data &d)
{
    for (int i = 0;i < 20; ++i)
    {
		boost::this_thread::sleep_for(3_ms);
        d.write();
    }
}

void reader(rw_data &d)
{
    int x;
    for (int i = 0;i < 10; ++i)
    {
		boost::this_thread::sleep_for(5_ms);
        d.read(&x);
        cout << "reader:"<< x << endl;
    }
}

void case7()
{
    rw_data d;
    thread_group pool;

    pool.create_thread(bind(writer,boost::ref(d)));
    pool.create_thread(bind(writer,boost::ref(d)));

    pool.create_thread(bind(reader,boost::ref(d)));
    pool.create_thread(bind(reader,boost::ref(d)));
    pool.create_thread(bind(reader,boost::ref(d)));
    pool.create_thread(bind(reader,boost::ref(d)));

    pool.join_all();
}


//////////////////////////////////////////

int main()
{
    case1();
    case2();
    case3();
    case4();
    case5();
    case6();
    case7();
}
