# Project push_swap


## Think about it

ac = 1 ==> return(0)

check av :
- [x] que des int
- [x] pas de depassement d'int
- [x] pas de doublon
- [ ] '+' peu être explicite ou implicite
* Needed ? (apparament oui cf p9 sujet)
- [ ] `./push_swap "1 2 4 0 9 7" doit fonctionner` (1 *av à split)

ERROR handler == "Error\n"

## select method based on ac
* ac <= 3 ==> max 3
* 3 < ac <= 5 ==> max 12
* 5 < ac >= 100 ==> 700 900 1100 1300 1500 (5 to 1 point)
* 100 < ac >= 500 ==> 5500 7000 8500 1000 11500 (5 to 1 point)
minimum to pass is 6pts (not sure)


### Who wears Sort Shorts ?
**Tests avec un groupe de nombres aléatoires**
[9 100 -2] == rra		==> [-2 9 100]
[9 -2 100] == sa		==> ""
[100 9 -2] == sa rra	==> ""
[100 -2 9] == ra		==> ""
[-2 9 100] 				==> ""
[-2 100 9] == rra sa	==> ""

**On a N! cas d'ordre possibles (ici 3! = 6) et il faut selectionner celui qui est ordonné.**
__Généralisation avec des couleurs__
```
[blue red green] ;

if (blue > red && blue > green) // blue is the biggest
{
	if (red > green)
		sa rra
	else
		ra
}
else if (blue < red && blue < green) // blue is the smallest
{
	if (red > green)
		rra sa
	else
		; // already shorted
}
else
{
	if (red > green)
		rra
	else
		sa
}
```

### We like sort shorts
Utilisation de la meme technique pour 5 ?
__5! = 120__ ==> **non**
Commencer a utiliser les deux stacks serai plus interessant

[8 5 7 6 -2] == ra pb pb sa pa pa  ==> [-2 5 6 7 8]

```
1. (put smallest to top then put it to b) * a.max_l/2
2. sort a
3. put all b to a
```
1.
	a[5 6 -2 8 7] == ra ra	==> a[-2 8 7 6 5] == pb	==> b[-2]
	a[8 7 6 5] ==	rra ==> a[5 8 7 6] == pb ==> b[5 -2]
2.
	a[8 7 6] == sa rra ==> a[6 7 8]
3.
	b[5 -2] == pa pa ==> a[-2 5 6 7 8]

Exemple du pdf : a[2 1 3 6 5 8] b[]
1.
	start		a[2 1 3 6 5 8]	b[]
	sa		==> a[1 2 3 6 5 8]	b[]
	pb		==> a[2 3 6 5 8]	b[1]
	pb pb	==> a[6 5 8]		b[1 2 3]
2.
	sa		==> a[5 6 8]		b[1 2 3]
3.
	pa		==> a[3 5 6 8]		b[1 2]
	pa		==> a[2 3 5 6 8]	b[1]
	pa		==> a[1 2 3 5 6 8]	b[]
==> 8 instructions


Pour 1. selectionne facon la plus rapide de remonter smallest
	si en position 2 (ou a[1]) => swap
	si position > (current_s / 2) ? reverse_rotate : rotate