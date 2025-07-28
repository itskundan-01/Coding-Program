let s1 = document.getElementById("sq1");
s1.addEventListener("mouseenter",function(){
    let num = Math.floor(Math.random()*100);
    s1.innerHTML=`<h1>${num}</h1>`;
})
s1.addEventListener("mouseleave",function(){
    s1.innerHTML=`<h1>${1}</h1>`;
})

let s2 = document.getElementById("sq2");
let clr = "green";
s2.addEventListener("mouseenter",function(){
    
    s2.style.backgroundColor=clr;
    if(clr=="green"){
        s2.style.backgroundColor="green";
        clr ="red";
    }
    else if(clr=="red"){
        s2.style.backgroundColor="red";
        clr ="green";
    }
})
s2.addEventListener("mouseleave",function(){
    s2.style.backgroundColor="white";
})

let s3 = document.getElementById("sq3");
s3.addEventListener("mouseenter",function(){
    let ca = Math.floor(Math.random()*256);
    let cb= Math.floor(Math.random()*256);
    let cc = Math.floor(Math.random()*256);
    let rclr = `rgb(${ca},${cb},${cc})`;
    s3.style.backgroundColor=rclr;
    console.log(rclr,ca,cb,cc);
})
s3.addEventListener("mouseleave",function(){
    s3.style.backgroundColor="white";
})


let s4 = document.getElementById("sq4");
s4.addEventListener("click",function(){
    let ca = Math.floor(Math.random()*256);
    let cb= Math.floor(Math.random()*256);
    let cc = Math.floor(Math.random()*256);
    s3.style.backgroundColor=`rgb(255,${cb},${cc})`;
    s2.style.backgroundColor=`rgb(${ca},255,${cc})`;
    s1.style.backgroundColor=`rgb(${ca},${cb},255)`;
})
s4.addEventListener("mouseleave",function(){
    s1.style.backgroundColor="white";
    s2.style.backgroundColor="white";
    s3.style.backgroundColor="white";
})