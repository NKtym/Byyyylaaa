#include <stdio.h>
#include <stdlib.h>

#include "quize_run.h"
#include "quizz_data.h"

int write_name(struct user users){
	printf("Введите ваше имя:");
	if(scanf("%s",&users.user_name)!=0)
		return 0;
	return -1;
}

int test_selection(struct user users){
	printf("Введите номер теста:");
	if(scanf("%d",&users.num_test)!=0)
		return users.num_test;
	return -1;
}

/*int choice_quizz(quizz quiz, user users){
	for(int i; i<10; i++){
		if(quiz.quizzNumber==user.num_test);
			return quizz[i];
	}
}
*/

struct answers quest(struct quizz* quiz,struct answers results, int questionCount, int optionCount){
	printf("Вопрос номер %d \n\n", quiz->question[questionCount].questionNumber+1);
	printf("%s \n",quiz->question[questionCount].questionText);
	for (answerOptions* i =quiz->question[questionCount].answerOptions; i!=NULL; i++){
		printf("%c\n",(*i).optionLetter);
		printf("%s\n",(*i).optionLetter);
	}
	char answer;
	printf("Введите ответ:");
	scanf("%c",&answer);
	printf("\n");
}

int percentage_of_completion(struct answers answer,struct user users){
	int goodanswers=0;
	int allquestion=100;//Бета
	for(int i=0; i<100; i++){
		goodanswers+=answer.correctness[i];
	}
	users.pass_percentage=goodanswers*100/allquestion;
	printf("Ваш результат:%d\n",users.pass_percentage);
	return 0;
}

int main(){
	struct user data;
	struct answers data2;
	struct quizz *data3;
	data3 = malloc(sizeof(*data3));
	data3->quizzNumber=1;
	data3->quizzName[0]='K';
	for(int i=0;i<4;i++){
		data3->question[i].questionNumber=i;
		data3->question[i].questionText[i]='К';
		data3->question[i].answerOptions[0].optionLetter='A';
		data3->question[i].answerOptions[0].optionText[0]='1';
		data3->question[i].answerOptions[0].isAnswerRight=0;
		data3->question[i].answerOptions[1].optionLetter='B';
		data3->question[i].answerOptions[1].optionText[1]='2';
		data3->question[i].answerOptions[1].isAnswerRight=1;
		data3->question[i].answerOptions[2].optionLetter='C';
		data3->question[i].answerOptions[2].optionText[2]='3';
		data3->question[i].answerOptions[2].isAnswerRight=0;
		data3->question[i].answerOptions[3].optionLetter='D';
		data3->question[i].answerOptions[3].optionText[3]='4';
		data3->question[i].answerOptions[3].isAnswerRight=0;
	}
	write_name(data);
	test_selection(data); 
	quest(data3,data2,0,0);
	quest(data3,data2,1,1);
	percentage_of_completion(data2,data);
	return 0;
}
