package vn.com.teachasians.quiz.service;

import vn.com.teachasians.quiz.model.quizType;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import vn.com.teachasians.quiz.repository.quizTypeRepo;

import java.util.List;

@Service
public class quizTypeServiceImpl implements quizTypeService{

    @Autowired
    private quizTypeRepo quiztyperepo;

    @Override
    public quizType addQuizType(quizType quiz) {
        if(quiz != null) {
            return quiztyperepo.save(quiz);
        }
        return null;
    }

    @Override
    public quizType updateQuizType(int id, quizType quiz) {
        if(quiz != null) {
            quizType quizWithId = quiztyperepo.getById(id);
            if(quizWithId != null) {
                quizWithId.setType(quiz.getType());
                quizWithId.setDescription(quiz.getDescription());
                return quiztyperepo.save(quizWithId);
            }
        }
        return null;
    }

    @Override
    public boolean deleteQuizType(int id) {
        if(id > 0) {
            quizType quizWithId = quiztyperepo.getById(id);
            if(quizWithId != null) {
                quiztyperepo.delete(quizWithId);
                return true;
            }
        }
        return false;
    }

    @Override
    public List<quizType> getAllQuiz() {
        return quiztyperepo.findAll();
    }

    @Override
    public quizType getQuizById(int id) {
        return quiztyperepo.getById(id);
    }
}
