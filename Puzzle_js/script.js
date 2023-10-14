var	inputs = readline().split(' ');
const	lightX = parseInt(inputs[0]);
const	lightY = parseInt(inputs[1]);
const	initialTx = parseInt(inputs[2]);
const	initialTy = parseInt(inputs[3]);
let		tX = initialTx;
let		tY = initialTy;

while (true)
{
	const remainingTurns = parseInt(readline());
	if (lightX > tX)
		{
			if (lightY > tY)
			{
				console.log('SE');
				tX++;
				tY++;
			}
			else if (lightY == tY)
			{
				console.log('E');
				tX++;
			}
			else
			{
				console.log('NE');
				tX++;
				tY--;
			}
		}
		else if (lightX == tX)
		{
			if (lightY > tY)
			{
				console.log('S');
				tY++;
			}
			else
			{
				console.log('N');
				tY--;
			}
		}
		else
		{
			if (lightY > tY)
			{
				console.log('SW');
				tX--;
				tY++;
			}
			else if (lightY == tY)
			{
				console.log('W');
				tX--;
			}
			else
			{
				console.log('NW');
				tX--;
				tY--;
			}
		}
}
