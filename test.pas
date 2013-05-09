program WriteName;
var
  i    : Integer;
  r    : Real;
  Name : String;
begin
  Write('Please tell me your name: ');
  ReadLn(Name);
  for i := 1 to 100 do
  begin
    WriteLn('Hello ', Name)
  end
  r := 123.3222E+12;
end.