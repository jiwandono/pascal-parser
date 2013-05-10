program coba(test);

begin
	a := 1;
	b := a + 2;

	if b > 2 then
		b := 10
	else
		b := 0;

	while b > 2 do
	begin
		b := b - 1;
		if b > 1 then
			a := a + 1;
	end;

	for a := 9 downto 1 do
		b := b - a;
end.
