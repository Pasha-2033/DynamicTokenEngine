#pragma once
#include <vector>
#include <algorithm>
/*
��������� ��������� �������
function = {										//��������� �������
	name = "addandadd"								//�������� �������
	args = {										//��������� ���������
		a = int										//�������� �������� � ���� ��� ���
		b = int	
		� = int	
		r1 = int	
		r2 = int	
	}
	sub_functions = {								//��������� �������, ������� ����� ���������� ������ 
		add = {a, b, r1}							//��������� ����� ��������� ����� ������������ ������ �������
		add = {a, c, r2}
	}
}
*/

namespace tokenfunction {
	struct functionfield {
		uint64_t name;								//��� ����
		std::vector<uint64_t> types;				//���� ������, ������� ����� ������� ����
	};
	struct argument {
		uint64_t name;								//��� ���������
		uint64_t type;								//��� ������
		uint64_t fieldtarget = 0;					//��� ���� �������, ���� ���������� ��������
		void* valuepointer;							//��������� �� ��������
	};
	struct functioncaller {
		basicfunction* functionpointer;				//��������� �� �������
		std::vector<uint64_t> args_name;			//����� ����������, ������� ��������� � �������
	};
	struct basicfunction {
		uint64_t name;								//��� �������
		bool isbasic;								//������� �������� ��� ������������
		std::vector<argument> defaultvalues;		//������ � ����������� �� �������� �� ���������
		virtual void execute(std::vector<argument> args) = 0;
		protected:
			std::vector<argument> filldefaultvalues(std::vector<argument> args);
	};
	struct function : basicfunction {
		std::vector<functioncaller> subfunctions;	//������ � ����������� �� �������
		bool isreliable;							//������� �������� ��� ������������
		void execute(std::vector<argument> args);
	};
	struct unreliablefunction : function {
		//to do
		//������ try catch �������
	};
}