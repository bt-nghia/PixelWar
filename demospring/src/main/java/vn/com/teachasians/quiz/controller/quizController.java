package vn.com.teachasians.quiz.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import vn.com.teachasians.quiz.service.quizTypeService;
import vn.com.teachasians.quiz.model.quizType;

import java.util.List;

@RestController
@RequestMapping("/quiz")
public class quizController {

    @Autowired
    private quizTypeService quizservice;

    @GetMapping("/")
    public String test() {
        return "nghia1234";
    }

    @PostMapping("/add-question-type")
    public quizType addQuizType(@RequestBody quizType quiztype) {
        return quizservice.addQuizType(quiztype);
    }

    @PutMapping("/update-question-type")
    public quizType updateQuestionType(@RequestParam("id") int id, @RequestBody quizType quiz) {
        return quizservice.updateQuizType(id, quiz);
    }

    @DeleteMapping("/delete-question-type/{id}")
    public boolean deleteQuestionType(@PathVariable("id") int id) {
        return quizservice.deleteQuizType(id);
    }

    @GetMapping("/list")
    public List<quizType> getAllQuestion() {
        return quizservice.getAllQuiz();
    }
}
