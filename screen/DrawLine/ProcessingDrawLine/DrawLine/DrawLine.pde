void setup()
{
 size(100,100); 
}

void draw()
{
 // clear screen to white
 background(255,255,255);
 // set colour to red
 stroke(255,0,0);
 // draw line from top left to bottom right
 line(0,0,width,height);
 // set colour to green
 stroke(0,255,0);
 // draw line from top right to bottom left
 line(width,0,0,height);
 // set colour to blue
 stroke(0,0,255);
 // draw line in center
 line(0,height/2,width,height/2);
// set colour to black
 stroke(0,0,0);
 // draw line in center
 line(width/2,0,width/2,height);
  
  
}
