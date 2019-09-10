<template>
    <div id="app">
        <!--背景虚化-->
        <div id="cover"></div>
        <Header></Header>
        <Todo></Todo>
        <Footer></Footer>
    </div>
</template>

<script>
import Header from './todo/header.vue'
import Footer from './todo/footer.jsx'
import Todo from './todo/todo.vue'
export default {
    //声明要使用Header组件
    components:{
        Header,
        Footer,
        Todo
    }
}
</script>
<!--说明此处css使用的预处理器,scoped使此处css代码只在这个组件内生效，其他组件中同名不会冲突-->
<style lang="stylus" scoped>
#app{
    height:100%;
    width:100%;
    position:absolute;
    left: 0;
    top: 0;
    right: 0;
    bottom: 0;
}
#cover{
    height:100%;
    width:100%;
    position:absolute;
    left: 0;
    top: 0;
    right: 0;
    bottom: 0;
    background-color: #eee;
    opacity: .5;
    z-index: -1;
}
</style>