let q1 = document.querySelector('#q1')
let op1 = document.querySelector('#op1')
let op2 = document.querySelector('#op2')
let op3 = document.querySelector('#op3')
let op4 = document.querySelector('#op4')
let q2 = document.querySelector('#q2')
document.querySelector('#op1').addEventListener('click', function() {
    op1.style.backgroundColor = 'red';
    q1.innerHTML = 'Incorrect';
});
document.querySelector('#op2').addEventListener('click', function() {
    op2.style.backgroundColor = 'green';
    q1.innerHTML = 'Correct';
});
document.querySelector('#op3').addEventListener('click', function() {
    op3.style.backgroundColor = 'red';
    q1.innerHTML = 'Incorrect';
});
document.querySelector('#op4').addEventListener('click', function() {
    op4.style.backgroundColor = 'red';
    q1.innerHTML = 'Incorrect';
});
document.querySelector('form').addEventListener('submit', function(e){
    let ans = document.querySelector('#ans').value;
    let answer = document.querySelector('#ans');
    e.preventDefault();
    if (ans == "Crocodile" || ans == "crocodile"){
        q2.innerHTML = 'Correct';
        answer.style.backgroundColor = 'green';
    }
    else{
        q2.innerHTML = 'Incorrect';
        answer.style.backgroundColor = 'red';
    }
})