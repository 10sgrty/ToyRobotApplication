#pragma once
#include "gtest/gtest.h"
#include "CController.h"

class CTestFixture :
	public ::testing::Test
{
public:
	CTestFixture();
	void SetUp();

	std::shared_ptr<CController> m_controller;
	int m_posX;
	int m_posY;
	Face m_face;
};

