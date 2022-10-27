#pragma once
#include <stdint.h>
#include <thread>
#include <semaphore>
#include "../../function/include/functionfactory.h"
using namespace std;
using namespace functionfactory;
namespace memory {
	namespace stream {
		struct createstreamstruct : basicfunction {
			using basicfunction::basicfunction;
			void execute(std::vector<void*>* argumentspointer, uint64_t* errorcodepointer, bool forced);	//to do
		};
		class stream {
			public:
				stream(basicfunction* function, uint64_t id, stream* caller) {}
				virtual ~stream() {}
				void execute(){}	//add function arguments
				uint64_t getid() { return 0; }
				void interrupt(uint64_t id) {}	//to do, interrupterid ������ ��������, ���� �� �� 0!
				void proceed(uint64_t id) {}	//to do, ���� id ���������, ������������ ������
				void killstream(uint64_t id) {}	//to do (��������� ����� ����� ����� ���� ����), ������� ����� � ���������� � ���

			private:
				stream* caller;
				uint64_t id;
				uint64_t interrupterid = 0;
				binary_semaphore semaphore = binary_semaphore(false);
				vector<void*> stack;
		};
		static vector<stream*> treads;
	}
}