package vn.com.teachasians.quiz.service;

import vn.com.teachasians.quiz.model.quizType;

import java.util.List;

public interface quizTypeService {
    quizType addQuizType(quizType quiz);
    quizType updateQuizType(int id, quizType quiz);
    boolean deleteQuizType(int id);
    List<quizType> getAllQuiz();
    quizType getQuizById(int id);
}
