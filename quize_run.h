#pragma once

#include "quizz_data.h"

struct user{
	char* user_name;
	int num_test;
	int pass_percentage;
};


struct answers{
	char answer[100];
	int correctness[100];	
};


int write_name(struct user users);
int test_selection(struct user users);
int percentage_of_completion(struct answers answer,struct user users);
struct answers quest(struct quizz* quiz,struct answers results, int questionCount, int optionCount);
