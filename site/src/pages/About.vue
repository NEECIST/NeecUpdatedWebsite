<template>
    <div class="about-app">
        <div class=about-container>
            <div class="about-row">
                <div class="about-title">
                    <h1>Quem somos?</h1>
                </div>
                <div class="about-content">
                    <p>
                        Associação sem fins lucrativos que reúne os estudantes de MEEC do IST. Somos formados por alunos que, através do seu trabalho voluntário, proporcionam diversas atividades aos seus colegas.
                    </p>
                </div>
            </div>
            <div class="about-row">
                <div class="about-title">
                    <h1 class="about-row">O que fazemos?</h1>
                </div>
                <div class="about-content">
                    <p>
                        Procuramos ajudar os alunos a intregarem-se no mercado de trabalho e dar formação extra-curricular. Organizamos workshops,estágios de verão, OpenDays e muito mais!
                    </p>
                </div>
            </div>
            <div class="about-row">
                <div class="about-title">
                    <h1 class="about-row">Por que o fazemos?</h1></div>
                <div class="about-content">
                    <p>
                        Queremos ajudar a complementar o normal percurso escolar, não só dos alunos de Eletrotecnia, como também de todos do IST.
                    </p>
                </div>
            </div>
            <div class="about-row">
                <div class="about-title">
                    <h1 class="about-row">Desde quando?</h1>
                </div>
                <div class="about-content">
                    <p>
                        Começámos em 2003, e já por mais de duas décadas temos vindo a crescer para te ajudar ao máximo.
                    </p>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
    export default {
        name: "about-page",
        components : {},
        data() {}
    }
</script>

<style>
    .about-app{
        padding-top: 70px;
    }
    .about-container{
        display: block;
    }
    .about-row{
        display: block;
        text-align: center;
    }
    .about-title{
        color: white;
        background-color: #009DE0;    
        padding: 20px;
        margin: 0%;
    }
    .about-content{
        padding: 50px;
        max-width: 1200px;
        margin: auto;
    }
</style>