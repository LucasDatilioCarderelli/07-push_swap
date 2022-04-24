<div align="center">
	<a href="https://www.42sp.org.br/">
		<img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/42-saopaulo.png" height=200>
	</a>
<h1> Push Swap </h1>
</div>

<h2 align="center">
	Project develop for <a href="https://github.com/LucasDatilioCarderelli/42Cursus"> 42Cursus </a>
</h2>

<p align="center">
  	<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
    	<img alt="Linkedin" src="https://img.shields.io/badge/Lucas_Datilio_Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" />
  	</a>
	<a href="https://github.com/LucasDatilioCarderelli" alt="login intra">
    	<img src="https://img.shields.io/badge/-ldatilio-gray?style=flat&logo=42&logoColor=white" />
	</a>
	<br>
    <img src="https://img.shields.io/github/last-commit/LucasDatilioCarderelli/02-Push_swap?color=blue">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/LucasDatilioCarderelli/02-Push_swap?color=blue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/LucasDatilioCarderelli/02-Push_swap?color=blue" />
</p>

<div align="center">
	<a href="https://github.com/LucasDatilioCarderelli/02-Push_swap">
		<img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/push_swap.png">
	</a>
	<h2> 96% [OK] </h2>
</div>

---

## Description
> This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, is needed to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

### Keywords
* ``Sorting algorithms``
* ``Battery concept and handling elements``
* ``Algorithm implementation``

### Skills
* ``Unix``
* ``Rigor``
* ``Imperative programming``
* ``Algorithms & AI``

## How it Work

### Small sort

<div align="center">
  <img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/push_swap_5.gif">
</div>

This algorithm run when we have ten o fewer arguments, it is kind of a selection sort with some optimization like a ``swap_a`` before locate the lowest number in stack a, the we push it to stack b, once the stack a is already sorted we send back the number from stack b to a in order.

### Long sort
<div align="center">
  <img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/push_swap_100_crop.gif">
</div>

Here lies the core algorithm in this project and i affectionately call as montain sort. It work with ten or more arguments and still pretty similiar from the small sort, but insted locating the smallest number, we iterate the stack and push any number lesser than the ``factor_to_push``.

This strategy is important becase just selecting the small number is very inefficient, so, we do a pre-sort selecting from the ``factor_to_push``, and them selecting the highest number in stack b and send back to a.

The ideia of this algorithm came from this [medium](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) where he uses chunks of values and push them in order and i adjust this chunk to be movable.

---

### Contact:
<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
	<img alt="Linkedin" src="https://img.shields.io/badge/Lucas_Datilio_Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" />
</a>
<a href="https://github.com/LucasDatilioCarderelli" alt="login intra">
	<img src="https://img.shields.io/badge/-ldatilio-gray?style=flat&logo=42&logoColor=white" />
</a>
