/**************************************************************************\
* Copyright (c) Kongsberg Oil & Gas Technologies AS
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
* Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
*
* Neither the name of the copyright holder nor the names of its
* contributors may be used to endorse or promote products derived from
* this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#define BOOST_TEST_NO_LIB 1
#include <boost/test/unit_test.hpp>
#include <boost/intrusive_ptr.hpp>
#include <cassert>
#include <cstdio>
#include <iostream>
#include "TestSuiteUtils.h"
#include "TestSuiteMisc.h"
using namespace SIM::Coin3D::Coin;
using namespace SIM::Coin3D::Coin::TestSuite;

BOOST_AUTO_TEST_SUITE(models_TestSuite);
const char *readError[] = { "Coin read error:", 0 };

BOOST_AUTO_TEST_CASE(models_coin_features_PickStyle_SHAPE_FRONTFACES_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/coin_features/PickStyle_SHAPE_FRONTFACES.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_coin_features_PickStyle_SHAPE_ON_TOP_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/coin_features/PickStyle_SHAPE_ON_TOP.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_coin_features_simple_texture3_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/coin_features/simple-texture3.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_coin_features_texture3_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/coin_features/texture3.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_coin_features_texture3transform_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/coin_features/texture3transform.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_all_iv_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/all-iv.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_array_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/array.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_cone_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/cone.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_cube_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/cube.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_group_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/group.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_indexedfaceset_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/indexedfaceset.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_material_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/material.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_misc_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/misc.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_multiplecopy_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/multiplecopy.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_rotated_cube_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/rotated_cube.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_sphere_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/sphere.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_text2_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/text2.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_texture2_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/texture2.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_dead_simple_texturecoordinate2_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/dead_simple/texturecoordinate2.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_driver_problems_trans_disappear_notworking_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/driver_problems/trans_disappear_notworking.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_io_correct_bug029_1_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/io/correct/bug029-1.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_io_correct_bug029_2_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/io/correct/bug029-2.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_io_correct_bug077_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/io/correct/bug077.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_io_correct_bug199_ok_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/io/correct/bug199-ok.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_io_correct_bug199_ok_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/io/correct/bug199-ok.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_io_correct_writeref_2_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/io/correct/writeref-2.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_io_correct_writeref_3_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/io/correct/writeref-3.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_io_correct_writeref_4_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/io/correct/writeref-4.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_io_correct_writeref_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/io/correct/writeref.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_annotation_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/annotation.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_antisquish_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/antisquish.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_array_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/array.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_asciitext_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/asciitext.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_basecolor_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/basecolor.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_blinker_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/blinker.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_aspectRatio_0_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/aspectRatio_0.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_aspectRatio_1_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/aspectRatio_1.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_aspectRatio_2_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/aspectRatio_2.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_aspectRatio_3_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/aspectRatio_3.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_aspectRatio_4_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/aspectRatio_4.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_aspectRatio_5_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/aspectRatio_5.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_viewportMapping_0_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/viewportMapping_0.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_viewportMapping_1_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/viewportMapping_1.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_viewportMapping_2_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/viewportMapping_2.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_viewportMapping_3_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/viewportMapping_3.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_camera_viewportMapping_4_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/camera/viewportMapping_4.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_clipplane_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/clipplane.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_cone_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/cone.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_cube_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/cube.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_cylinder_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/cylinder.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_directionallight_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/directionallight.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_drawstyle_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/drawstyle.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_environment_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/environment.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_faceset_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/faceset.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_file_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/file.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_font_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/font.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_fontstyle_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/fontstyle.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_image_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/image.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_includefile_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/includefile.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_indexedfaceset_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/indexedfaceset.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_indexedlineset_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/indexedlineset.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_indexedtrianglestripset_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/indexedtrianglestripset.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_levelofdetail_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/levelofdetail.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_lightmodel_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/lightmodel.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_lineset_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/lineset.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_locatehighlight_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/locatehighlight.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_lod_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/lod.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_markerset_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/markerset.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_material_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/material.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_materialbinding_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/materialbinding.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_matrixtransform_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/matrixtransform.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_multiplecopy_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/multiplecopy.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_normalbinding_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/normalbinding.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_packedcolor_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/packedcolor.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_pendulum_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/pendulum.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_pointlight_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/pointlight.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_pointset_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/pointset.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_polygonoffset_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/polygonoffset.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_quadmesh_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/quadmesh.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_resettransform_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/resettransform.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_rotation_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/rotation.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_rotationxyz_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/rotationxyz.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_rotor_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/rotor.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_scale_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/scale.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_shapehints_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/shapehints.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_shuttle_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/shuttle.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_sphere_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/sphere.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_spotlight_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/spotlight.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_switch_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/switch.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_text2_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/text2.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_text3_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/text3.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_texture2_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/texture2.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_texture2transform_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/texture2transform.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_texturecoordinatebinding_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/texturecoordinatebinding.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_texturecoordinatedefault_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/texturecoordinatedefault.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_texturecoordinateenvironment_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/texturecoordinateenvironment.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_texturecoordinateplane_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/texturecoordinateplane.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_transform_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/transform.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_transformseparator_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/transformseparator.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_translation_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/translation.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_trianglestripset_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/trianglestripset.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_oiv_compliance_units_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/oiv_compliance/units.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_tessellation_PointOnEdge_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/tessellation/PointOnEdge.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_tessellation_RenderIsMissingTriangles_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/tessellation/RenderIsMissingTriangles.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_tessellation_StripAroundHole_iv) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/tessellation/StripAroundHole.iv", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_groups_lod_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/groups/lod.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_groups_switch_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/groups/switch.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_misc_directionallight_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/misc/directionallight.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_misc_includefile_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/misc/includefile.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_misc_pointlight_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/misc/pointlight.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_misc_spotlight_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/misc/spotlight.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_misc_wwwinline_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/misc/wwwinline.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_coordinate3_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/coordinate3.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_fontstyle_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/fontstyle.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_info_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/info.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_material_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/material.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_matrixtransform_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/matrixtransform.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_rotation_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/rotation.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_scale_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/scale.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_shapehints_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/shapehints.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_texture2_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/texture2.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_texture2transform_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/texture2transform.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_transform_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/transform.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_properties_translation_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/properties/translation.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_shapes_asciitext_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/shapes/asciitext.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_shapes_cone_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/shapes/cone.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_shapes_cube_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/shapes/cube.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_shapes_cylinder_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/shapes/cylinder.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_shapes_indexedfaceset_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/shapes/indexedfaceset.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_shapes_indexedlineset_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/shapes/indexedlineset.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_shapes_pointset_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/shapes/pointset.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml1_0_shapes_sphere_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml1.0/shapes/sphere.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml97_misc_fan_in_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml97/misc/fan-in.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml97_script_simple_boolean_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml97/script/simple-boolean.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_CASE(models_vrml97_sensors_touch_and_fan_in_wrl) { ResetReadErrorCount(); test_file("E:/hanwenzhi_code/coin3d/backup/coin-4.0.0/models/vrml97/sensors/touch_and_fan_in.wrl", &testCorrectFile); }
BOOST_AUTO_TEST_SUITE_END();
