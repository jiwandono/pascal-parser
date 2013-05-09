program test3;

const
	c_i = 1000;
	c_r = 2.5E+12;
	c_s = 'Hello';
	c_c = 'X';

type
	type_a = integer;
	type_b = string;

var
	i: integer;
	r: real;
	s: string;
	c: char;
	a, b: integer;

begin
	a := 5;
	b := 9;
	i := c_i + (1234 - 5678) * 2 div a;
	r := 123.32 / c_r;
	s := 'Hola amigo';
	c := s[0];

	if(a < b) then writeln('<');
	if(a <= b) then writeln('<=');
end.