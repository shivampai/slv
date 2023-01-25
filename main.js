
function load() {
    document.getElementById('run-api-1').src = 'https://blynk.cloud/external/api/update?token=V7x28SbjavwU0O9dz32aNMgguwi9XHNw&v0=1'
    document.getElementById('run-api-2').src = 'https://blynk.cloud/external/api/update?token=V7x28SbjavwU0O9dz32aNMgguwi9XHNw&v1=1'
    document.getElementById('run-api-3').src = 'https://blynk.cloud/external/api/update?token=V7x28SbjavwU0O9dz32aNMgguwi9XHNw&v5=No Car Standing'
    document.getElementById('left-street-light-btn').innerHTML = 'Turn Off'
    document.getElementById('right-street-light-btn').innerHTML = 'Turn Off'
    left_status = true
    right_status = true
}
function toggleLeft() {
    if (left_status) {
        left_status = false;
        document.getElementById('left-street-light-status').src = 'img/bulb_off.png'
        document.getElementById('run-api-1').src = 'https://blynk.cloud/external/api/update?token=V7x28SbjavwU0O9dz32aNMgguwi9XHNw&v0=1'
        document.getElementById('left-street-light-btn').innerHTML = 'Turn On'
    } else {
        left_status = true;
        document.getElementById('left-street-light-status').src = 'img/bulb_on.png'
        document.getElementById('run-api-1').src = 'https://blynk.cloud/external/api/update?token=V7x28SbjavwU0O9dz32aNMgguwi9XHNw&v0=0'
        document.getElementById('left-street-light-btn').innerHTML = 'Turn Off'
    }
}
function toggleRight() {
    new Notification("Hello")
    if (right_status) {
        right_status = false;
        document.getElementById('right-street-light-status').src = 'img/bulb_off.png'
        document.getElementById('run-api-1').src = 'https://blynk.cloud/external/api/update?token=V7x28SbjavwU0O9dz32aNMgguwi9XHNw&v1=1'
        document.getElementById('right-street-light-btn').innerHTML = 'Turn On'
    } else {
        right_status = true;
        document.getElementById('right-street-light-status').src = 'img/bulb_on.png'
        document.getElementById('run-api-1').src = 'https://blynk.cloud/external/api/update?token=V7x28SbjavwU0O9dz32aNMgguwi9XHNw&v1=0'
        document.getElementById('right-street-light-btn').innerHTML = 'Turn Off'
    }
}
// document.getElementById('status').innerHTML = 'On';
// document.getElementById('switch').innerHTML = '<circle cx="150" cy="150" r="150"  fill="red" id="switch"></circle > ';
// document.getElementById('iframe').src = 'https://blynk.cloud/external/api/update?token=V7x28SbjavwU0O9dz32aNMgguwi9XHNw&v0=1';
// document.getElementById('diagram').src = 'circuit_on.png';
