<template>
    <section class="real-app">
        <input 
            type="text"
            class="add-input"
            autofocus="autofocus"
            placeholder="接下去要做什么？"
            @keyup.enter="addTodo"
        >
        <!--输入并按了enter时才执行此操作，@等于v-on-->
        <Item 
            :todo="todo"
            v-for="todo in filteredTodos"
            :key="todo.id"    
            @del="deleteTodo"
        />
        <Tabs 
            :filter="filter" 
            :todos="todos"
            @toggle="toggleFilter"
            @clearAll="clearAllCompleted"
        />
    </section>
</template>

<script>
import Item from './item.vue'
import Tabs from './tabs.vue'
let id = 0
//尽量把数据操作放在顶层，把数据声明放在顶层
export default {
    data(){
        return {
            todos:[],
            filter: 'all'
        }
    },
    components:{
        Item,
        Tabs
    },
    computed:{
        filteredTodos(){
            if(this.filter === 'all'){
                return this.todos
            }
            else{
                const completed = this.filter === 'completed'
                return this.todos.filter(todo => completed === todo.completed)
            }
        }
    },
    methods: {
        addTodo(e) {
            this.todos.unshift({
                id:id++,
                content: e.target.value.trim(),
                completed:false
            })
            //每次增加清空内容
            e.target.value = ''
        },
        deleteTodo(id){
            this.todos.splice(this.todos.findIndex(todo => todo.id === id),1)
        },
        toggleFilter(state){
            this.filter = state
            
        },
        clearAllCompleted(){
            //filter() 方法创建一个新的数组，新数组中的元素是通过检查指定数组中符合条件的所有元素。
            this.todos = this.todos.filter(todo => !todo.completed)

        }
    }
}
</script>

<style lang="stylus" scoped>
.real-app{
    width:600px;
    margin:0 auto;
    box-shadow:0 0 5px #666;
}
.add-input{
    position :relative;
    width:100%;
    font-size :24px;
    font-family: inherit;
    font-weight:inherit;
    line-height:1.4em;
    outline:none;
    color:inherit;
    padding:16px 16px 16px 60px;
    border:1px solid #999;
    box-shadow: inset 0 -1px 5px 0 #eee;
    box-sizing :border-box;
    background:#fff;

}
</style>