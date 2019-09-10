<template>
    <!--动态class，使用[]写class可以传任意值，包括数组等-->
    <div :class="['todo-item',todo.completed ? 'completed':'']">
        <input 
            type="checkbox"
            class="toggle"
            v-model="todo.completed"
        
        >
        <label class="words">{{todo.content}}</label>
        <button class="destory" @click="deleteTodo">
            <span class="isaX"></span>
        </button>
    </div>
</template>

<script>
export default {
    props:{
        todo:{
            type:Object,
            required:true
        }
    },
    methods:{
        deleteTodo(){
            //把子组件触发方法之后调用的父组件的方法传进来，这样父组件就可以知道子组件调用了哪些方法，把参数传回给父组件
            this.$emit('del',this.todo.id)
        }
    }
}
</script>

<style lang="stylus" scoped>
.todo-item{
    position :relative;
    font-size :24px;
    font-family: inherit;
    font-weight:inherit;
    line-height:1.4em;
    outline:none;
    color:inherit;
    padding:16px 16px 16px 16px;
    border:1px solid #999;
    border-top:none;
    background:#fff;
}
.todo-item:hover{
    .destory{
        display:block;
    }
}
.toggle{
    cursor:pointer;
    position:relative;
    top:.2em;
    appearance:none;
    border-radius:50%;
    width:20px;
    height:20px;
    border:1px solid #999;
    outline:none;
}
.toggle:checked{
    background:#d5ffc0;
    box-shadow:inset 0 0 0 2px #fff;
    border:1px solid #d5ffc0;
}
.words{
    padding:0 0 0 10px;
}
.completed{
    text-decoration:line-through;
    color:#d5ffc0;
}
//用css实现的xx
.isaX{
    display: inline-block;
    width: 15px;
    height: 2px;
    background: #ff9a81;
    transform: rotate(45deg);
}
.isaX::after{
    content: '';
    display: block;
    width: 15px;
    height: 2px;
    background: #ff9a81;
    transform: rotate(-90deg);
}
.destory{
    cursor:pointer;
    position:relative;
    width:40px;
    height:40px;
    text-align:center;
    border:none;
    outline:none;
    background:#fff;
    top:-.5em;
    //元素居最右
    float:right;
    display:none;
}
//给按钮一个点击的效果
.destory:active{
    .isaX{
        transform: rotate(180deg);
    }
}
</style>