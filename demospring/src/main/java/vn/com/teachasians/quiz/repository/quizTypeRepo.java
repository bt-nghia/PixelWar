package vn.com.teachasians.quiz.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import vn.com.teachasians.quiz.model.quizType;
import org.springframework.stereotype.Repository;

@Repository
public interface quizTypeRepo extends JpaRepository<quizType, Integer> {

}
