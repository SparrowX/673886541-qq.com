[X,map]=imread('my.gif');
imshow(X,map)
newmap = rgb2gray(map);
imshow(X,newmap)
B = rgb2gray(map);
imwrite(X,B,'mygray.gif')
