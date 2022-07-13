package vn.com.teachasians.quiz.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import vn.com.teachasians.quiz.model.subject;

public interface subjectRepo extends JpaRepository<subject, Integer> {
}
