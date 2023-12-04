document.addEventListener('DOMContentLoaded', function () {
    const questions = [
      {
        question: 'What is the capital of France?',
        answers: ['Paris', 'Berlin', 'London', 'Madrid'],
        correctAnswer: 'Paris',
      },
      {
        question:'who is prime minister of india?',
        answers:['Rahul Gandhi','Narendra modi','Cristiano Ronaldo','Solomon'],
        correctAnswer:'Narendra modi'
      },
        {
          question: 'What is the capital of Japan?',
          answers: ['Beijing', 'Seoul', 'Tokyo', 'Bangkok'],
          correctAnswer: 'Tokyo',
        },
        {
          question: 'Which planet is known as the Red Planet?',
          answers: ['Mars', 'Venus', 'Jupiter', 'Saturn'],
          correctAnswer: 'Mars',
        },
        {
          question: 'What is the largest mammal?',
          answers: ['Elephant', 'Blue Whale', 'Giraffe', 'Hippopotamus'],
          correctAnswer: 'Blue Whale',
        },
        {
          question: 'Who wrote "Romeo and Juliet"?',
          answers: ['Charles Dickens', 'William Shakespeare', 'Jane Austen', 'Mark Twain'],
          correctAnswer: 'William Shakespeare',
        },
        {
          question: 'What is the currency of Australia?',
          answers: ['Dollar', 'Euro', 'Yen', 'Pound'],
          correctAnswer: 'Dollar',
        },
        {
            question:'who won the icc 2023 world cup?',
            answers:['India','south Africa ','Australia','New Zealand'],
            correctAnswer:'Australia'
        }
        // Add more questions as needed
      ];
      
  
    let currentQuestionIndex = 0;
    const questionElement = document.querySelector('.questions p');
    const answerButtons = document.querySelectorAll('.btn');
    const nextButton = document.querySelector('.next');
  
    function showQuestion() {
      const currentQuestion = questions[currentQuestionIndex];
      questionElement.textContent = currentQuestion.question;
  
      answerButtons.forEach((button, index) => {
        button.textContent = currentQuestion.answers[index];
        button.style.backgroundColor = ''; // Reset button color
        button.addEventListener('click', () => handleAnswer(index));
      });
  
      nextButton.style.display = 'none';
    }
  
    function handleAnswer(selectedIndex) {
      const currentQuestion = questions[currentQuestionIndex];
      const selectedAnswer = currentQuestion.answers[selectedIndex];
  
      if (selectedAnswer === currentQuestion.correctAnswer) {
        // Set button color to green for correct answer
        answerButtons[selectedIndex].style.backgroundColor = 'green';
        console.log('Correct!');
      } else {
        // Set button color to red for incorrect answer
        answerButtons[selectedIndex].style.backgroundColor = 'red';
        console.log('Incorrect!');
      }
  
      nextButton.style.display = 'block';
      answerButtons.forEach((button) => button.removeEventListener('click', handleAnswer));
    }
  
    function handleNext() {
      currentQuestionIndex++;
      if (currentQuestionIndex < questions.length) {
        showQuestion();
      } else {
        // You can add logic for what happens when all questions are answered
        console.log('Quiz completed!');
      }
    }
  
    // Event listener for the "Next" button
    nextButton.addEventListener('click', handleNext);
  
    // Initial display of the first question
    showQuestion();
  });
  