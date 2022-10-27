#pragma once
#include "pch.h"
#ifdef ALGEBRA_EXPORTS
#define ALGEBRA_API __declspec(dllexport)
#else
#define ALGEBRA_API __declspec(dllimport)
#endif
using namespace functionfactory;
namespace functions {
	namespace algebra {
		//constructors
		//(+)
		struct ALGEBRA_API int_add_function : basicfunction {
			using basicfunction::basicfunction;
			void execute(std::vector<void*>* argumentspointer, uint64_t* errorcodepointer, bool forced);
		};
		struct ALGEBRA_API float_add_function : basicfunction {
			using basicfunction::basicfunction;
			void execute(std::vector<void*>* argumentspointer, uint64_t* errorcodepointer, bool forced);
		};
		struct ALGEBRA_API add_function : muxfunction {
			using muxfunction::muxfunction;
		};
		//(-)
		struct ALGEBRA_API int_sub_function : basicfunction {
			using basicfunction::basicfunction;
			void execute(std::vector<void*>* argumentspointer, uint64_t* errorcodepointer, bool forced);
		};
		struct ALGEBRA_API float_sub_function : basicfunction {
			using basicfunction::basicfunction;
			void execute(std::vector<void*>* argumentspointer, uint64_t* errorcodepointer, bool forced);
		};
		//(*)
		struct ALGEBRA_API int_mul_function : basicfunction {
			using basicfunction::basicfunction;
			void execute(std::vector<void*>* argumentspointer, uint64_t* errorcodepointer, bool forced);
		};
		struct ALGEBRA_API float_mul_function : basicfunction {
			using basicfunction::basicfunction;
			void execute(std::vector<void*>* argumentspointer, uint64_t* errorcodepointer, bool forced);
		};
		//(/)
		struct ALGEBRA_API int_div_function : basicfunction {
			using basicfunction::basicfunction;
			void execute(std::vector<void*>* argumentspointer, uint64_t* errorcodepointer, bool forced);
		};
		struct ALGEBRA_API float_div_function : basicfunction {
			using basicfunction::basicfunction;
			void execute(std::vector<void*>* argumentspointer, uint64_t* errorcodepointer, bool forced);
		};
		//(%)
		//instances
		//(+)
		int_add_function int_add {
			0,	//name
			{	//default values
				nullptr,
				nullptr,
				nullptr
			}
		};
		float_add_function float_add {
			0,
			{
				nullptr,
				nullptr,
				nullptr
			}
		};
		add_function add {
			0,	//name
			{	//defaultvalues
				nullptr,
				nullptr,
				nullptr
			},
			{	//callings
				{
					&int_add,
					{
						{0, false},
						{1, false},
						{2, false}
					}
				},
				{
					&float_add,
					{
						{0, false},
						{1, false},
						{2, false}
					}
				}
			},
			{   //valuetypes
				{
					(void*)0,
					(void*)1,
					(void*)2,
					(void*)3
				},
				{
					(void*)0,
					(void*)1,
					(void*)2,
					(void*)3
				},
				{
					(void*)0,
					(void*)1,
					(void*)2,
					(void*)3
				}
			},
			nullptr //&mux
		};
		//(-)
		int_sub_function int_sub {
			0,
			{
				nullptr,
				nullptr,
				nullptr
			}
		};
		float_sub_function float_sub {
			0,
			{
				nullptr,
				nullptr,
				nullptr
			}
		};
		//(*)
		int_mul_function int_mul {
			0,
			{
				nullptr,
				nullptr,
				nullptr
			}
		};
		float_mul_function float_mul {
			0,
			{
				nullptr,
				nullptr,
				nullptr
			}
		};
		//(/)
		int_div_function int_div {
			0,
			{
				nullptr,
				nullptr,
				nullptr
			}
		};
		float_div_function float_div {
			0,
			{
				nullptr,
				nullptr,
				nullptr
			}
		};
		//(%)
		//function vector
		extern ALGEBRA_API std::vector<basicfunction*> getfunctions() {
			return std::vector<basicfunction*>(
				/*{
					&int_add,
					&float_add,
					&add,
					&int_sub,
					&float_sub,
					&int_mul,
					&float_mul,
					&int_div,
					&float_div
				}*/
				{}
			);
		}
		
	}
}
extern _declspec(dllexport) int getftemp() {
	return -2000;
}