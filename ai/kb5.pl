sum(X, Y) :-
    S is X + Y,
    write(S).

sub(X, Y) :-
    S is X - Y,
    write(S).

mul(X, Y) :-
    M is X * Y,
    write(M).

div(X, Y) :-
    D is X / Y,
    write(D).
