# Philosophers
<p align="center">
<img src="An_illustration_of_the_dining_philosophers_problem.png" alt="100" width="300"/>
</p>

## Project overview

This project is the [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).
It aims at using multi threading and mutexes to create a communication pattern between multiple threads.

The program is launched with:
1. Number of philosopher
2. Time to eat (ms).
3. Time to die (ms).
4. Time to sleep (ms).
5. Amount of meals each philosopher must have before ending the program (optional)

Each Philosopher represents a thread. Each Philosopher has a fork (mutex). Hence all Philosophers can't eat at the same time. So there needs to be a system implemented in the code where the fork mutexes are locked for a philosopher to eat and unlock when done eating. The overall programs needs to make sure no Philosopher dies unpredictibly.

## What I learned

1. Multi-threading.
2. Mutexes.
3. Thread communication.
4. Avoiding deadlocks and Data Races by using mutexes.
5. Optimizing code to avoid fluctuation in program behaviour between different case scenarios.
