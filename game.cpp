#include "game.h"
#include <iostream>
#include <random>

void Game::menu() { 
  while(true){
    char option;
    std::cout << "==================\n";
    std::cout << "===== Wordle =====\n";
    std::cout << "==================\n\n";
    std::cout << "1. Play!\n";
    std::cout << "2. Exit.\n";
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (option) {
      case '1': start(); break;
      case '2': std::cout << "Exiting..."; return;
      default: std::cout << "not an option";
    }
  }
}

void Game::start() {
  guesses.clear();
  colorHistory.clear();

  std::string secret_word = picker(); // function that picks a random word in the wordlist we have
  bool won = false;

  for (int attempt = 0; attempt < 6; attempt++) {
    updateBoard();
    std::cout << "\nAttempt " << (attempt + 1) << " of 6\n";

    std::string guess = getValidGuess();
    char colors[5]; // char array of colors

    won = evaluateGuess(guess, secret_word, colors);

    // Store the guess and colors
    guesses.push_back(guess);
    colorHistory.push_back(std::string(colors, 5));

    if (won) {
      updateBoard();
      std::cout << "\nYou guessed it in " << (attempt + 1) << " tries!\n";
      return;
    }
  }

  // If we get here, player lost
  updateBoard();
  std::cout << "\nGame Over! The word was: " << secret_word << "\n";
}

bool Game::evaluateGuess(const std::string &guess, const std::string &secret_word, char colors[5]) {
  // First pass: Mark all exact matches (green)
  for (int i = 0; i < 5; i++) {
    if (guess[i] == secret_word[i]) {
      colors[i] = 'G'; // Green - correct letter, correct position
    } else {
      colors[i] = 'X'; // Default to gray
    }
  }

  // Second pass: Mark letters in wrong position (yellow)
  // Need to count how many of each letter are available for yellow marking
  for (int i = 0; i < 5; i++) {
    if (colors[i] == 'X') { // Only check non-green positions
      // Count how many times this letter appears in secret_word and isn't already marked green
      int availableCount = 0;
      int usedCount = 0;

      for (int j = 0; j < 5; j++) {
        if (secret_word[j] == guess[i]) {
          availableCount++;
          if (colors[j] == 'G' && guess[j] == guess[i]) {
            usedCount++;
          }
        }
      }

      // Count how many yellows we've already assigned for this letter
      for (int j = 0; j < i; j++) {
        if (guess[j] == guess[i] && colors[j] == 'Y') {
          usedCount++;
        }
      }

      if (availableCount > usedCount) {
        colors[i] = 'Y'; // Yellow - correct letter, wrong position
      }
    }
  }

  // Check if player won
  bool won = true;
  for(int i = 0; i < 5; i++){
    if (colors[i] != 'G'){
      won = false;
      break;
    }
  }

  return won;
}

void Game::updateBoard() {
  std::cout << "\n==================\n";
  std::cout << "   WORDLE BOARD\n";
  std::cout << "==================\n";

  // Display all previous guesses with colors
  for (size_t i = 0; i < guesses.size(); i++) {
    std::cout << "  ";
    for (int j = 0; j < 5; j++) {
      char letter = guesses[i][j];
      char color = colorHistory[i][j];

      // Display letter with color indicator
      if (color == 'G') {
        std::cout << "\033[42;30m " << (char)toupper(letter) << " \033[0m"; // Green background
      } else if (color == 'Y') {
        std::cout << "\033[43;30m " << (char)toupper(letter) << " \033[0m"; // Yellow background
      } else {
        std::cout << "\033[47;30m " << (char)toupper(letter) << " \033[0m"; // Gray background
      }
    }
    std::cout << "\n";
  }

  // Display remaining empty rows
  for (size_t i = guesses.size(); i < 6; i++) {
    std::cout << "  _ _ _ _ _\n";
  }

  std::cout << "==================\n";
}

std::string Game::getValidGuess() {
  while (true) {
    std::string currentGuess;
    std::cout << "Type a 5 letter word: ";
    std::getline(std::cin, currentGuess);

    if (currentGuess.length() == 5) {
      return currentGuess;
    }
  }
}

std::string Game::picker() {
  std::random_device rd; // functions as a device i guess like foo
  static std::mt19937 gen(rd()); // the generator
  std::uniform_int_distribution<> dist(0, words.size() - 1); // so from 0 to words size minus 1 
  std::string secret_word = words[dist(gen)]; // this preforms the action of assigning the random word to become the variable secret word
  return secret_word; // returns it to another function ? or what does this do again ?
}

Game::Game() {
  words = {
      "about", "above", "abuse", "actor", "acute", "admit", "adopt", "adult",
      "after", "again", "agent", "agree", "ahead", "alarm", "album", "alert",
      "align", "alike", "alive", "allow", "alone", "along", "alter", "angel",
      "anger", "angle", "angry", "apart", "apple", "apply", "arena", "argue",
      "arise", "array", "aside", "asset", "audio", "avoid", "awake", "award",
      "aware", "badly", "baker", "bases", "basic", "basis", "beach", "began",
      "begin", "being", "below", "bench", "billy", "birth", "black", "blame",
      "blind", "block", "blood", "board", "boost", "booth", "bound", "brain",
      "brand", "bread", "break", "breed", "brief", "bring", "broad", "broke",
      "brown", "build", "built", "buyer", "cable", "calif", "carry", "catch",
      "cause", "chain", "chair", "chart", "chase", "cheap", "check", "chest",
      "chief", "child", "china", "chose", "civil", "claim", "class", "clean",
      "clear", "click", "clock", "close", "coach", "coast", "could", "count",
      "court", "cover", "crack", "craft", "crash", "crazy", "cream", "crime",
      "cross", "crowd", "crown", "crude", "cycle", "daily", "dance", "dated",
      "dealt", "death", "debut", "delay", "depth", "doing", "doubt", "dozen",
      "draft", "drama", "drank", "drawn", "dream", "dress", "drill", "drink",
      "drive", "drove", "dying", "eager", "early", "earth", "eight", "elite",
      "empty", "enemy", "enjoy", "enter", "entry", "equal", "error", "event",
      "every", "exact", "exist", "extra", "faith", "false", "fault", "fiber",
      "field", "fifth", "fifty", "fight", "final", "first", "fixed", "flash",
      "fleet", "floor", "fluid", "focus", "force", "forth", "forty", "forum",
      "found", "frame", "frank", "fraud", "fresh", "front", "fruit", "fully",
      "funny", "giant", "given", "glass", "globe", "going", "grace", "grade",
      "grand", "grant", "grass", "great", "green", "gross", "group", "grown",
      "guard", "guess", "guest", "guide", "happy", "harry", "heart", "heavy",
      "hence", "henry", "horse", "hotel", "house", "human", "ideal", "image",
      "index", "inner", "input", "issue", "japan", "jimmy", "joint", "jones",
      "judge", "known", "label", "large", "laser", "later", "laugh", "layer",
      "learn", "lease", "least", "leave", "legal", "lemon", "level", "lewis",
      "light", "limit", "links", "lives", "local", "logic", "loose", "lower",
      "lucky", "lunch", "lying", "magic", "major", "maker", "march", "maria",
      "match", "maybe", "mayor", "meant", "media", "metal", "might", "minor",
      "minus", "mixed", "model", "money", "month", "moral", "motor", "mount",
      "mouse", "mouth", "movie", "music", "needs", "never", "newly", "night",
      "noise", "north", "noted", "novel", "nurse", "occur", "ocean", "offer",
      "often", "order", "other", "ought", "paint", "panel", "paper", "party",
      "peace", "peter", "phase", "phone", "photo", "piece", "pilot", "pitch",
      "place", "plain", "plane", "plant", "plate", "point", "pound", "power",
      "press", "price", "pride", "prime", "print", "prior", "prize", "proof",
      "proud", "prove", "queen", "quick", "quiet", "quite", "radio", "raise",
      "range", "rapid", "ratio", "reach", "ready", "refer", "right", "rival",
      "river", "robin", "roger", "roman", "rough", "round", "route", "royal",
      "rural", "scale", "scene", "scope", "score", "sense", "serve", "seven",
      "shall", "shape", "share", "sharp", "sheet", "shelf", "shell", "shift",
      "shirt", "shock", "shoot", "short", "shown", "sight", "since", "sixth",
      "sixty", "sized", "skill", "sleep", "slide", "small", "smart", "smile",
      "smith", "smoke", "solid", "solve", "sorry", "sound", "south", "space",
      "spare", "speak", "speed", "spend", "spent", "split", "spoke", "sport",
      "staff", "stage", "stake", "stand", "start", "state", "steam", "steel",
      "stick", "still", "stock", "stone", "stood", "store", "storm", "story",
      "strip", "stuck", "study", "stuff", "style", "sugar", "suite", "super",
      "sweet", "table", "taken", "taste", "taxes", "teach", "terry", "texas",
      "thank", "theft", "their", "theme", "there", "these", "thick", "thing",
      "think", "third", "those", "three", "threw", "throw", "tight", "times",
      "title", "today", "topic", "total", "touch", "tough", "tower", "track",
      "trade", "train", "treat", "trend", "trial", "tribe", "trick", "tried",
      "tries", "troop", "truck", "truly", "trust", "truth", "twice", "under",
      "undue", "union", "unity", "until", "upper", "upset", "urban", "usage",
      "usual", "valid", "value", "video", "virus", "visit", "vital", "vocal",
      "voice", "waste", "watch", "water", "wheel", "where", "which", "while",
      "white", "whole", "whose", "woman", "women", "world", "worry", "worse",
      "worst", "worth", "would", "wound", "write", "wrong", "wrote", "young",
      "youth"};
}
