<template>
    <section>
        <div class="loader">
            <div class="dot" style="--i:0;"></div>
            <div class="dot" style="--i:1;"></div>
            <div class="dot" style="--i:2;"></div>
            <div class="dot" style="--i:3;"></div>
            <div class="dot" style="--i:4;"></div>
            <div class="dot" style="--i:5;"></div>
            <div class="dot" style="--i:6;"></div>
            <div class="dot" style="--i:7;"></div>
            <div class="dot" style="--i:8;"></div>
            <div class="dot" style="--i:9;"></div>
        </div>
        <h2>Loading...</h2>
        <div class="loader">
            <div class="dot" style="--i:0;"></div>
            <div class="dot" style="--i:1;"></div>
            <div class="dot" style="--i:2;"></div>
            <div class="dot" style="--i:3;"></div>
            <div class="dot" style="--i:4;"></div>
            <div class="dot" style="--i:5;"></div>
            <div class="dot" style="--i:6;"></div>
            <div class="dot" style="--i:7;"></div>
            <div class="dot" style="--i:8;"></div>
            <div class="dot" style="--i:9;"></div>
        </div>
    </section>
</template>

<script>
export default {
  name: "loader-component"
}
</script>

<style scoped>
*{
    margin:0;
    padding:0;
    box-sizing: border-box;
}
section{
    position:relative;
    width:100%;
    height:100%;
    display:flex;
    justify-content:center;
    align-items:center;
    flex-direction: column;
    background: white;
    animation: changeColor 5s linear infinite;
}
section h2{
    color:#009DE0;
    font-family:consolas;
    font-weight:300;
    letter-spacing:10px;
}
section .loader{
    position:relative;
    display:flex;
}
section .loader .dot{
    position:relative;
    display:block;
    width:20px;
    height:20px;
    background:#009DE0;
    box-shadow: 0 0 10px #009DE0,
                0 0 20px #009DE0,
                0 0 40px #009DE0,
                0 0 60px #009DE0,
                0 0 80px #009DE0,
                0 0 100px #009DE0;
    margin:20px 10px;
    transform: scale(0.1);
    border-radius: 50%;
    animation: animateDot 2s linear infinite;
    animation-delay: calc(0.1s * var(--i));
}
section .loader:last-child .dot{
    animation-delay: calc(-0.1s * var(--i));
}
@keyframes animateDot
{
    0%
    {
        transform: scale(0.1);
    }
    10%
    {
        transform: scale(1);
    }
    50%,100%
    {
        transform: scale(0.1);
    }
}
@keyframes changeColor
{
    0%
    {
        transform: hue-rotate(0 deg);
    }
    100%
    {
        transform: hue-rotate(360 deg);
    }
}
</style>