#pragma once

struct answerOptions {
  char optionLetter;
  char optionText[100];
  int isAnswerRight;
};
typedef struct answerOptions answerOptions;

struct questions {
  int questionNumber;
  char questionText[100];
  answerOptions answerOptions[10];
};
typedef struct questions question;

struct quizz {
  int quizzNumber;
  char quizzName[100];
  question question[100];
};
