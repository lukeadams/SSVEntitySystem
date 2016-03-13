cmake_minimum_required(VERSION 3.0)

set(CPM_MODULE_NAME SSVEntitySystem)
include(./cmake/modules/CPM-mod.cmake)

SET(SSVDepsRoot "https://github.com/lukeadams/")
CPM_AddModule("SSVCMake"
	GIT_REPOSITORY "${SSVDepsRoot}SSVCMake"
	GIT_TAG "cpm")
CPM_AddModule("SSVUtils"
	GIT_REPOSITORY "${SSVDepsRoot}SSVUtils"
	GIT_TAG "cpm")

CPM_AddModule("vrm_pp"
	GIT_REPOSITORY "${SSVDepsRoot}vrm_pp"
	GIT_TAG "cpm")
CPM_ExportAdditionalIncludeDir("./include")

CPM_InitModule(${CPM_MODULE_NAME})
