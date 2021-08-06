# IMC Technical Assignment – Software Engineer (C++)

This is a summary of two small projects that form a Technical Assignment
for a Software Engineer (C++) position at IMC.

The first test name is "Visitor" with the following description:

> Test 1. Visitor
> Create an interface or abstract base class 'Shape'. Implement three concrete Shapes: 'Circle', 'Rectangle', 'Triangle'. Apply the visitor pattern to your data model. Write an AreaVisitor that computes the area of the shapes. Write a program that makes arbitrary instances of the data model and applies the AreaVisitor.

The second test name is "" with the following description:

> Test 2. Paper Scissors Rock
> Paper Scissors Rock is a game for two players. Each player simultaneously opens his/her hand to display a symbol:
> Fist equals rock.
> Open hand equals paper.
>Showing the index and middle finger equals scissors.
> The winner is determined by the following schema:
> Paper beats (wraps) rock.
> Rock beats (blunts) scissors.
> Scissors beats (cuts) paper.
> Write a program that plays Paper Scissors Rock between the computer and a real player.
> You should be able to play the game n times before the program exits.

# Compilation

Tests and the root folder include a Makefile that will create executables for the
`main` as well as `unit tests` to those elements.

# Docker

This project has been compiled to run on docker with a simple command:

```
docker build -t imc-test .
$ docker run -it --rm --name running-imc img-test
```

# TODO

There are some pending tasks:

- Add unit, functional and performance testing
- Visitor: Add more shapes, possibly use functoinoids to abstract even more the visitor pattern
- PSR: Clear the screen on every iteration
