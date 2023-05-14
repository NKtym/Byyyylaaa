#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quize_run.h"
#include "quizz_data.h"

#define MAX_CNT_ANSWERS 10

int get_username(struct user* users){
	scanf(" %s",users->username);
	return 0;
}

int quizz_select(struct user* users){
	if(scanf("%d",&users->quizzNum)!=0)
		return users->quizzNum;
	return -1;
}

/*int choice_quizz(quizz quiz, user users){
	for(int i; i<10; i++){
		if(quiz.quizzNumber==user.num_test);
			return quizz[i];
	}
}
*/

int print_answer_options(struct quizz* quiz,int questionCount){
	for (answerOptions* i =quiz->question[questionCount].answerOptions; i->optionLetter!=0; i++){
		printf("%c) ",(*i).optionLetter);
		printf("%s\n",(*i).optionText);
	}
	return 0;
}

struct answers get_answer(struct answers* results,int optionCount){
	char answ;
	scanf(" %c",&answ);
	results->answer[optionCount]=answ;
	return *results;
}

int check_answers(struct quizz* quiz,struct answers* results,int questionCount,int optionCount){
	for(int i=0;i<MAX_CNT_ANSWERS;i++){	
		if(results->answer[optionCount]==quiz->question[questionCount].answerOptions[i].optionLetter){
			results->isCorrect[optionCount]=quiz->question[questionCount].answerOptions[i].isAnswerRight;
			return 0;
		}
		else
			continue;
	}
	return -1;
}

int get_pass_percentage(struct answers* answer,struct user* users,int questionCount){
	int goodAnswers=0;
	int allQuestion=questionCount;
	for(int i=0; i<100; i++){
		goodAnswers+=answer->isCorrect[i];
	}
	users->passPercentage=goodAnswers*100/allQuestion;
	printf("Ваш результат:%d\n",users->passPercentage);
	return 0;
}

struct user passage_quizz(struct answers* answer,struct user* users, struct quizz* quiz){
	int questionCount=0;
	int optionCount=0;
	printf("Введите ваше имя:\n");
	get_username(users);
	printf("Введите номер теста:\n");	
	quizz_select(users);
	for (question* i=quiz->question; i->questionText[0]!=0; i++){
		printf("Вопрос номер %d \n", quiz->question[questionCount].questionNumber+1);
		printf("%s \n",quiz->question[questionCount].questionText);
		print_answer_options(quiz,questionCount);
		printf("Введите ответ:\n");
		get_answer(answer,optionCount);
		check_answers(quiz,answer,questionCount,optionCount);	
		optionCount++;
		questionCount++;
	}
	get_pass_percentage(answer,users,questionCount);
	return *users;
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
	passage_quizz(data2,data,data3);
	return 0;
}
