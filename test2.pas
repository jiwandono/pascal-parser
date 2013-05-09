program Test2;

type
	setering=packed array[1 .. 255]of char;
	hintejer=0 .. 65535;

var
	kalimat:string;
	angka:integer;
	kumpulan_angka:array[1 .. 16]of integer;
	kumpulan_real: array[1 .. 16]of real;

begin
	kalimat:='Ini adalah kalimat <=> ngawur *&%#^!$%';
	angka:=(124+456)*(123 div 4);
	writeln(kalimat);
	writeln(angka);

	while(angka>100)do
	begin
		writeln(angka);
		angka:=angka-1000;
	end;
end.
