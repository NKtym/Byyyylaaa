#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quize_run.h"
#include "quizz_data.h"

int write_name(struct user* users){
	printf("Введите ваше имя:");
	if(scanf(" %s",users->user_name)!=0)
		return 0;
	return -1;
}

int test_selection(struct user* users){
	printf("Введите номер теста:");
	if(scanf("%d",&users->num_test)!=0)
		return users->num_test;
	return -1;
}

/*int choice_quizz(quizz quiz, user users){
	for(int i; i<10; i++){
		if(quiz.quizzNumber==user.num_test);
			return quizz[i];
	}
}
*/

int сonclusion_quest(struct quizz* quiz,int questionCount){
	printf("Вопрос номер %d \n\n", quiz->question[questionCount].questionNumber+1);
	printf("%s \n",quiz->question[questionCount].questionText);
	for (answerOptions* i =quiz->question[questionCount].answerOptions; i->optionLetter!=NULL; i++){
		printf("%c) ",(*i).optionLetter);
		printf("%s\n",(*i).optionText);
	}
	return 0;
}

struct answers answer_quest(struct answers* results,int optionCount){
	char answ;
	printf("Введите ответ:");
	scanf(" %c",&answ);
	results->answer[optionCount]=answ;
	printf("\n");
	return *results;
}

int Validation(struct quizz* quiz,struct answers* results,int questionCount,int optionCount){
	for(int i=0;i<4;i++){	
		if(results->answer[optionCount]==quiz->question[questionCount].answerOptions[i].optionLetter){
			results->correctness[optionCount]=quiz->question[questionCount].answerOptions[i].isAnswerRight;
			return 0;
		}
		else
			continue;
	}
	return -1;
}

int percentage_of_completion(struct answers* answer,struct user* users,int questionCount){
	int goodanswers=0;
	int allquestion=questionCount;
	for(int i=0; i<100; i++){
		goodanswers+=answer->correctness[i];
	}
	users->pass_percentage=goodanswers*100/allquestion;
	printf("Ваш результат:%d\n",users->pass_percentage);
	return 0;
}

int main(){
	struct user *data;
	struct answers *data2;
	struct quizz *data3;
	data = malloc(sizeof(*data));
	data2 = malloc(sizeof(*data2));
	data3 = malloc(sizeof(*data3));
	data3->quizzNumber=1;
	data3->quizzName[0]='L';
	for(int i=0;i<4;i++){
		data3->question[i].questionNumber=i;
		data3->question[i].questionText[i]='P';
		data3->question[i].answerOptions[0].optionLetter='A';
		data3->question[i].answerOptions[0].optionText[0]='1';
		data3->question[i].answerOptions[0].isAnswerRight=0;
		data3->question[i].answerOptions[1].optionLetter='B';
		data3->question[i].answerOptions[1].optionText[0]='2';
		data3->question[i].answerOptions[1].isAnswerRight=1;
		data3->question[i].answerOptions[2].optionLetter='C';
		data3->question[i].answerOptions[2].optionText[0]='3';
		data3->question[i].answerOptions[2].isAnswerRight=0;
		data3->question[i].answerOptions[3].optionLetter='D';
		data3->question[i].answerOptions[3].optionText[0]='4';
		data3->question[i].answerOptions[3].isAnswerRight=0;
	}
	write_name(data);
	test_selection(data); 
	сonclusion_quest(data3,0);
	answer_quest(data2,0);
	Validation(data3,data2,0,0);
	percentage_of_completion(data2,data,1);
	return 0;
}
