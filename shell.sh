## Example (hello script)
```bash
#!/bin/bash
echo "Hello, world!"
```
Output:
```bash
$ chmod +x hello
$ ./hello
Hello, world!
```

---

```bash
mylang="Pennsylvania Dutch"
echo "I speak $mylang."
echo 'I speak $mylang.'

vech=Bus
n=10
echo $vech
echo $n
```

---

## Input / Output
```bash
echo "Your first name please:"
read fname
echo "Hello $fname, Let's be friends!"
```

---

## Conditional Control Statement: if
```bash
echo "Enter a number"
read choice
if [ $choice -gt 0 ]
then
    echo "$choice number is positive"
else
    echo "$choice number is negative"
fi
```

---

## Loops in Shell Scripts
```bash
for i in 1 2 3 4 5
do
    echo "Welcome $i times"
done
```

### while Loop
```bash
i=1; n=1
while [ $i -le 10 ]
do
    echo "$n * $i =" `expr $i \* $n`
    i=`expr $i + 1`
done
```

---

```bash
read var
case $var in
    1) echo "One" ;;
    2) echo "Two" ;;
    3) echo "Three" ;;
    4) echo "Four" ;;
    *) echo "Sorry, it is bigger than Four" ;;
esac
```

---

## String Conversion Examples

### Uppercase to Lowercase
```bash
VAR1=BASHSHELLSCRIPTING
echo $VAR1 | tr '[A-Z]' '[a-z]'
```

### Lowercase to Uppercase
```bash
VAR1=bashshellscripting
echo $VAR1 | tr '[a-z]' '[A-Z]'
```

### Convert only first character to uppercase
```bash
VAR1=bashshell
VAR2=${VAR1^}
echo $VAR2
```

### Convert specific characters (like a, d, e)
```bash
VAR1=bashshell
VAR2=${VAR1^^[ade]}
echo $VAR2
```

### Convert only first character to lowercase
```bash
VAR1=SURENDRAKUMAR
VAR2=${VAR1,}
echo $VAR2
```
