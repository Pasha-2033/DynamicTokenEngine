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
	struct argument {
		uint64_t name = 0;							//��� ���������
		uint64_t type = 0;							//��� ������
		uint64_t fieldtarget = 0;					//��� ���� �������, ���� ���������� ��������
		void* valuepointer = nullptr;				//��������� �� ��������
	};
	struct basicfunction {
		virtual ~basicfunction(){}
		uint64_t name = 0;							//��� �������
		bool isbasic = false;						//������� �������� ��� ������������
		std::vector<argument> defaultvalues;		//������ � ����������� �� �������� �� ���������
		std::vector<std::vector<uint64_t>> types;	//���� ������, ������� ������ ������� ����
		virtual void execute(std::vector<argument> args) = 0;
		protected:
			std::vector<argument> filldefaultvalues(std::vector<argument> args);
	};
	struct functioncaller {
		basicfunction* functionpointer = nullptr;	//��������� �� �������
		std::vector<uint64_t> args_name;			//����� ����������, ������� ��������� � �������
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