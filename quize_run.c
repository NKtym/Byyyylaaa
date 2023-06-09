#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quize_run.h"
#include "quizz_data.h"

#define MAX_CNT_ANSWERS 10

int get_username(struct user* users){
	if(scanf(" %s",users->username))
		return 0;
	return -1;
}

int quizz_select(struct user* users){
	if(scanf("%d",&users->quizzNum)!=0)
		return 0;
	return -1;
}

/*int choice_quizz(quizz quiz, user users){
	for(int i; i<10; i++){
		if(quiz.quizzNumber==user.num_test);
			return quizz[i];
	}
}
*/

void print_answer_options(struct quizz* quiz,int questionCount){
	for (answerOptions* i =quiz->question[questionCount].answerOptions; i->optionLetter!=0; i++){
		printf("%c) ",(*i).optionLetter);
		printf("%s\n",(*i).optionText);
	}
}

int get_answer(struct answers* results,int optionCount){
	char answ;
	if(scanf(" %c",&answ)!=0){
		results->answer[optionCount]=answ;
		return 0;
	}
	return -1;
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
	if(users->passPercentage>=0 || users->passPercentage<=100)
		return 0;
	return -1;
}

struct user passage_quizz(struct answers* answer,struct user* users, struct quizz* quiz){
	int questionCount=0;
	int optionCount=0;
	printf("Введите ваше имя:\n");
	if(get_username(users)!=0)
		printf("Не коректный ввод имени пользователя");
	printf("Введите номер теста:\n");	
	if(quizz_select(users)!=0)
		printf("Не коректный ввод номера текста");
	for (question* i=quiz->question; i->questionText[0]!=0; i++){
		printf("Вопрос номер %d \n", quiz->question[questionCount].questionNumber+1);
		printf("%s \n",quiz->question[questionCount].questionText);
		print_answer_options(quiz,questionCount);
		printf("Введите вариант ответа(Ответ должен быть введён с большой буквы английского алфавита):\n");
		if(get_answer(answer,optionCount)!=0)
			printf("Не коректный ввод варианта ответа");
		if(check_answers(quiz,answer,questionCount,optionCount)!=0)
			printf("В базе данных нет такого варианта ответа");
		optionCount++;
		questionCount++;
	}
	if(get_pass_percentage(answer,users,questionCount)==0)
		printf("Ваш результат: %d из 100\n",users->passPercentage);
	else
		printf("Ошибка при подсчёте результата");
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
