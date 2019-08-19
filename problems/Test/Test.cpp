﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void setZeroes(vector<vector<int>>& matrix) 
{
	int m = matrix.size();
	if (m == 0) return;
	int n = matrix[0].size();

	bool bZeroH = (matrix[0][0] == 0);
	bool bZeroV = (matrix[0][0] == 0);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				if (i == 0) bZeroH = true;
				else matrix[i][0] = 0;
				if (j == 0) bZeroV = true;
				else matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < m; i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 1; j < n; j++) matrix[i][j] = 0;
		}
	}

	for (int j = 1; j < n; j++)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 1; i < m; i++) matrix[i][j] = 0;
		}
	}
	if (bZeroH)
	{
		for (int j = 0; j < n; j++) matrix[0][j] = 0;
	}
	if (bZeroV)
	{
		for (int i = 0; i < m; i++) matrix[i][0] = 0;
	}
}


int main()
{
	vector<vector<vector<int>>> TESTS;
	//vector<int> K;
	vector<vector<vector<int>>> ANSWERS;

	TESTS.push_back(StringToVectorVectorInt("[[1, 0]]"));
	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0]]"));

	TESTS.push_back(StringToVectorVectorInt("[[1, 0, 3]]"));
	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0, 0]]"));

	TESTS.push_back(StringToVectorVectorInt("[[1, 1, 1],[1, 0, 1],[1, 1, 1]]"));
	ANSWERS.push_back(StringToVectorVectorInt("[[1, 0, 1],[0, 0, 0],[1, 0, 1]]"));

	TESTS.push_back(StringToVectorVectorInt("[[0, 1, 2, 0],[3, 4, 5, 2],[1, 3, 1, 5]]"));
	ANSWERS.push_back(StringToVectorVectorInt("[[0, 0, 0, 0],[0, 4, 5, 0],[0, 3, 1, 0]]"));

	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		//auto ans = setZeroes(TESTS[i]);
		printVectorVectorInt(TESTS[i]);
		setZeroes(TESTS[i]);
		cout << checkAnswer<decltype(TESTS[i])>(TESTS[i], ANSWERS[i]) << endl;
	}
}



//int main()
//{
//	vector<TreeNode *> N;
//	vector<int> K;
//	vector<bool> A;
//
//	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
//	//K.push_back(3);
//	A.push_back(true);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,null,null,4,4"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		cout << N[i] << endl;
//		//DrawTreeNode(N[i]);
//
//		bool ans = isBalanced(N[i]);
//		cout << checkAnswer<bool>(ans, A[i]) << endl;
//		//DrawTreeNode(ans);
//
//	}
//}



//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = nullptr;
//	StringToListNode(&pHead, "[4,7,5,3]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	for (auto p : lists)
//	{
//		PrintLinkList(p);
//		pHead = sortList(p);
//		PrintLinkList(pHead);
//		cout << endl;
//	}
//}


