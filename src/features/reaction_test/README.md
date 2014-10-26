# Reaction Test
The reaction test feature enables players to win a small amount of money by answering a quiz of mixed difficulty in the chat box. The tests are backed by different drivers, providing different kinds of questions, each of which can produce questions of different complexities.

## Driver: Calculation-based reaction tests
Presents the players with a calculation which has to be solved. The calculations come in different difficulties.

  * **Easy** *|X [+-] Y [+-] Z|*. Both X and Z will be in the range of [-10, 30], where Y will be in the range of [1, 99].
    * Example: -5 + 81 - 10
    * Example: 25 - 5 + -5
  * **Normal** *|(X [+-] Y) * Z|*. Both X and Y will be in the range of [-20, 50], where Z will be in the range of [2, 5].
    * Example: (-10 + 30) * 3
    * Example: (5 - - 10) * 5
  * **Hard** *|X * Y [+-] Z|*. Each of X, Y and Z will be in the range of [15, 99].
    * Example: 20 * 25 + 90
    * Example: 53 * 87 - 42

An easy test will be used in 30% of the cases, a normal test in 50% of the cases and a hard test in 20% of them.

## Driver: Random string-based reaction tests
Presents the players with a string containing random characters. Some characters (I, O, 0) have been removed because they look too similar to other characters.

An easy test will be used in 75% of the cases, which means the string's length will be six characters. The other 25% of tests will be done using a test of normal difficulty, where the string's length will be ten characters.
