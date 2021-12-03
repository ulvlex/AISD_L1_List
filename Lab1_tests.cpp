#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab1\list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1tests
{
	TEST_CLASS(Lab1tests)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			list list;
			Assert::IsTrue(list.get_size() == 0);
		}
		TEST_METHOD(Push_back_method)
		{
			list list;
			list.push_back(2);
			list.push_back(3);
			Assert::IsTrue(list.get_size() == 2);
			list::node* buf = list.head;
			Assert::IsTrue(buf->info == 2 && (buf->next)->info == 3);
		}
		TEST_METHOD(Push_front_method)
		{
			list list;
			list.push_front(2);
			list.push_front(3);
			Assert::IsTrue(list.get_size() == 2);
			list::node* buf = list.head;
			Assert::IsTrue(buf->info == 3 && (buf->next)->info == 2);
		}
		TEST_METHOD(Pop_back_method)
		{
			list list;
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			Assert::IsTrue(list.get_size() == 3);
			list.pop_back();
			list::node* buf = list.head;
			Assert::IsTrue(buf->info == 2);
			buf = buf->next;
			Assert::IsTrue(buf->info == 3);
			buf = buf->next;
			Assert::IsTrue(buf == NULL);
			Assert::IsTrue(list.get_size() == 2);
		}
		TEST_METHOD(Pop_front_method)
		{
			list list;
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			Assert::IsTrue(list.get_size() == 3);
			list.pop_front();
			list::node* buf = list.head;
			Assert::IsTrue(buf->info == 3);
			buf = buf->next;
			Assert::IsTrue(buf->info == 4);
			Assert::IsTrue(list.get_size() == 2);
		}
		TEST_METHOD(Insert_method)
		{
			list list;
			list.push_back(2);
			list.push_back(3);
			Assert::IsTrue(list.get_size() == 2);
			list.insert(4, 1);
			list::node* buf = list.head;
			Assert::IsTrue(buf->info == 4);
			buf = buf->next;
			Assert::IsTrue(buf->info == 2);
			buf = buf->next;
			Assert::IsTrue(buf->info == 3);
			Assert::IsTrue(list.get_size() == 3);
		}
		TEST_METHOD(At_method)
		{
			list list;
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			Assert::IsTrue(list.at(2) == 3);
		}
		TEST_METHOD(Remove_method)
		{
			list list;
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			list.remove(2);
			Assert::IsTrue(list.get_size() == 2);
			list::node* buf = list.head;
			Assert::IsTrue(buf->info == 2);
			buf = buf->next;
			Assert::IsTrue(buf->info == 4);
		}
		TEST_METHOD(Get_size_method)
		{
			list list;
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			Assert::IsTrue(list.get_size() == 3);
		}
		TEST_METHOD(Clear_method)
		{
			list list;
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			list.clear();
			Assert::IsTrue(list.get_size() == 0);
			list::node* buf = list.head;
			Assert::IsTrue(buf == NULL);
			buf = list.tail;
			Assert::IsTrue(buf == NULL);
		}
		TEST_METHOD(Set_method)
		{
			list list;
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			list.set(5, 2);
			list::node* buf = list.head;
			Assert::IsTrue(buf->info == 2);
			buf = buf->next;
			Assert::IsTrue(buf->info == 5);
			buf = buf->next;
			Assert::IsTrue(buf->info == 4);
			Assert::IsTrue(list.get_size() == 3);
		}
		TEST_METHOD(Insert_list_method)
		{
			list list1;
			list1.push_back(2);
			list1.push_back(3);
			list1.push_back(4);
			
			list list2;
			list2.push_back(5);
			list2.push_back(6);
		
			list1.insertList(list2, 2);
			Assert::IsTrue(list1.get_size() == 5);
			list::node* buf = list1.head;
			Assert::IsTrue(buf->info == 2);
			buf = buf->next;
			Assert::IsTrue(buf->info == 5);
			buf = buf->next;
			Assert::IsTrue(buf->info == 6);
			buf = buf->next;
			Assert::IsTrue(buf->info == 3);
			buf = buf->next;
			Assert::IsTrue(buf->info == 4);
		}
	};
}
