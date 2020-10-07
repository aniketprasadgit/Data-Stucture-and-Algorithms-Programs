var data = [2,4,55,1,6,3,71,29,7];

// taking user input
var ip = parseInt(prompt("Enter Number"));

// Linear Search

var start = 0;
var end = data.length - 1;
for (var i = 0; i < data.length / 2; i++) {
    if ((ip == data[start]) || (ip == data[end])) {
      document.write("Found");
    }
    start++;
    end--;
}  
