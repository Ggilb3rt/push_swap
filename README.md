# Project push_swap
Note de mes reflexions autour du projet, ce readme n'a pas vraiment pour but de vous aider mais plutôt de m'aider.

## Think about it

ac = 1 ==> return(0)

check av :
- [x] que des int
- [x] pas de depassement d'int
- [x] pas de doublon
- [x] '+' peu être explicite ou implicite (probleme arg_overflow() resolut)
* Needed ? (apparament oui cf p9 sujet; en fait non, bash parse tout seul, pas zsh)
- [ ] `./push_swap "1 2 4 0 9 7" doit fonctionner` (1 *av à split)

ERROR handler == "Error\n"

## select method based on ac
* ac <= 3 ==> max 3
* 3 < ac <= 5 ==> max 12
* 5 < ac >= 100 ==> 700 900 1100 1300 1500 (5 to 1 point)
* 100 < ac >= 500 ==> 5500 7000 8500 10000 11500 (5 to 1 point)
minimum to pass is 6pts (not sure)


## Who wears Sort Shorts ?
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

find smallest
a[8 4 2 5] ==> depart i = 0 (si a[i+1] < a[i] ? i = i+1 : i)*3 ; i = 2 ==> ra ra pb
a[0 5 8 4] ==> depart i = 1 (si a[i+1] < a[i] ? i = i+1 : i)*2 ; i = 2 ==> rra pb
a[0 0 5 8] ==> 	"" 						""			 		*1 ; i = 0 ==> pb pb

### Maximuns sort short
n = 3 ==> **2**
n = 5 ==> **10**
__(Worst case)__
* smallest in center ==> ra ra pb
* now n = 4 ==> rra rra pb
* now n = 3 ==> max 2
* send back from b ==> pa pa
n = 6 ==> **15** (see below)


## Something big is comming
Radix sort a l'air plutot cool et rapide. O = (n * log(n))
### Le principe
a[45 100 4 568 90 7 32]

1. On place chaque nombre dans une boite en fonction de la valeur de l'unite :
__dans l'ordre de la stack bien sûr__
boite 0 : 0 0 0 0 0 90 100
boite 1
boite 2 : 32
boite 3
boite 4 : 4
boite 5 : 45
boite 6
boite 7 : 7
boite 8 : 568
boite 9

2. On remet tout le monde dans la boite principale :
__en respectant l'ordre : premier entré premier sorti (pas necessaire pour le premier tour ?)__
a[90 100 32 4 45 7 568]

3. On boucle sur 1. avec les dizaines
boite 0 : 0 0 0 0 7 4 100
boite 3 : 32
boite 4 : 45
boite 6 : 568
boite 9 : 90

4. On boucle sur 2.
a[100 4 7 32 45 568 90]

5. Etc...
boite 0 : 0 0 90 45 32 7 4
boite 1 : 100
boite 5 : 568

a[4 7 32 45 90 100 568] ==> tadaaa !

**NOTE : penser a faire "rrb pa" pour remetre dans le bon ordre dans la stack a**

### Comment je fais avec les négatifs ?
Convertir chaque nombre par sa position une fois rangé
a[78 -8 1 58 -10] == magic human sort ==> [-10 -8 1 58 78]
a[4   1 2  3   0]

Ce qui est chiant c'est de devoir deja trier avant de trier...
ou alors
```
x = 0;
while (!(all be change))
{
	find_smallest_pos => change value a[] to x ; a[a->smallest_pos] = x
	remove find_smallest_pos form (all be change) == (don't check him in next turn)
	x++
}
```
how to perfome remove ?
```
already_find_smallest_pos[a->max_l] = bzero()
new_val = 0;
while (already_find_smallest_pos(contient un 0))
{
	if (!already_find_smallest_pos[])
		find_smallest_pos => change value a[] to x ; a[a->smallest_pos] = new_val
		already_find_smallest_pos[find_smallest_pos] = 1
		new_val++
	i++
}

```
a[-2 35 8] ; al[0 0 0]
a[0 35 8] ; al[1 0 0]
a[0 35 1] ; al[1 0 1]
a[0 2 1] ; al[1 1 1]

tmp[] en position tmp[0] = position plus petit a[]
		en position tmp[1] = position deuxieme plus petit a[]

a[-2 35 8] ; al[-1 -1 -1]
a[-2 35 8] ; al[0 -1 -1]
a[-2 35 8] ; al[0 -1 1]
a[-2 35 8] ; al[0 2 1]
a[i] = al[i];
free(al)

### C'est bien mignon mais j'ai que deux stacks de dispo
Le binaire est ton amis stack a == 1, stack b == 0
int => 4 bytes donc 32 bits donc 32 passages au maximum.
Mais avec la reduction n appartient à [0;n) (pour le moment [0;n.max_val)...)
Donc si n = 100, n_binary = 1100100 ==>		8 passages maximum
Donc si n = 500, n_binary = 111110100 ==>	10 passages maximum

## Les operateurs binaires
>> (decalage vers la droite | right shift)
<< (""			""	 gauche)
&	(bit by bit AND)
|	(bit by bit OR)