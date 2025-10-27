const words = ["python", "javascript", "coding", "developer", "keyboard", "challenge", "project", "function"];
let time = 10;
let score = 0;
let currentWord = "";

const wordElement = document.getElementById("word");
const inputElement = document.getElementById("input");
const timeElement = document.getElementById("time");
const scoreElement = document.getElementById("score");
const messageElement = document.getElementById("message");
const restartButton = document.getElementById("restart");

function getRandomWord() {
  return words[Math.floor(Math.random() * words.length)];
}

function showWord() {
  currentWord = getRandomWord();
  wordElement.textContent = currentWord;
}

function updateScore() {
  score++;
  scoreElement.textContent = score;
}

function gameOver() {
  messageElement.textContent = "Time's up! Your final score is " + score;
  inputElement.disabled = true;
}

function startGame() {
  time = 10;
  score = 0;
  inputElement.disabled = false;
  inputElement.value = "";
  scoreElement.textContent = score;
  timeElement.textContent = time;
  messageElement.textContent = "";
  showWord();

  const timer = setInterval(() => {
    time--;
    timeElement.textContent = time;
    if (time === 0) {
      clearInterval(timer);
      gameOver();
    }
  }, 1000);
}

inputElement.addEventListener("input", () => {
  if (inputElement.value === currentWord) {
    updateScore();
    inputElement.value = "";
    showWord();
    time += 2;
  }
});

restartButton.addEventListener("click", startGame);

startGame();
