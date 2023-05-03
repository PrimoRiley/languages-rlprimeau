help :- write('This is sample Prolog DB Defining Adventure Time. Get to know the characters'), nl,
write('   COMMANDS '), nl,
write(' appeared_in(2)'), nl,
write(' appeared_with(2)'), nl,
write(' friends(2)'), nl,
write(' brothers(2)'), nl,
write(' enemies(2)'), nl,
write(' wins_against(2)').

% Facts
character('Finn').
character('Jake').
character('Princess Bubblegum').
character('Marceline').
character('Ice King').
character('BMO').
character('Lumpy Space Princess').
character('Flame Princess').
character('All characters').
character('No characters').

appearance('Finn', 'Pilot').
appearance('Jake', 'Pilot').
appearance('Princess Bubblegum', 'Slumber Party Panic').
appearance('Marceline', 'Evicted!').
appearance('Ice King', 'Prisoners of Love').
appearance('BMO', 'Business Time').
appearance('Lumpy Space Princess', 'Trouble in Lumpy Space').
appearance('Flame Princess', 'Hot to the Touch').

relationship('Finn', 'Jake', 'Brothers').
relationship('Finn', 'Princess Bubblegum', 'Friend').
relationship('Finn', 'Ice King', 'Enemies').
relationship('Jake', 'Lady Rainicorn', 'Girlfriend').
relationship('Ice King', 'Gunther', 'Pet').

stronger_than('Finn', 'Ice King').
stronger_than('Marceline', 'Finn').
stronger_than('BMO', 'All characters').


% Rules
appeared_in(Character, Episode) :- appearance(Character, Episode).
appeared_with(Character1, Character2) :- appearance(Character1, Episode), appearance(Character2, Episode).
friends(Character1, Character2) :- relationship(Character1, Character2, 'Friend').
siblings(Character1, Character2) :- relationship(Character1, Character2, 'Brothers').
enemies(Character1, Character2) :- relationship(Character1, Character2, 'Enemies').
wins_against(Character1, Character2) :- stronger_than(Character1, Character).

