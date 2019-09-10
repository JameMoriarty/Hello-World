<template>
    <div class="helper">
        <span class="left">{{unFinishedTodoLength}} items left</span>
        <span class="tabs">
            <span 
            v-for="state in states"
            :key="state"
            :class="['state', filter === state ? 'actives':'']"
            @click="toggleFilter(state)"
            >
                {{state}}
            </span>
            <!--filter是选中状态-->
        </span>
        <span class="clear" @click="clearAllCompleted">Clear Compeletes</span>
    </div>
</template>

<script>
export default {
    props:{
        filter:{
            type:String,
            require:true,
        },
        todos:{
            type:Array,
            require:true
        }
    },
    data(){
        return {
            states:['all','active','completed']
        }
    },
    computed:{
        unFinishedTodoLength(){
            return this.todos.filter(todo => !todo.completed).length
        }    
    },
    methods:{
        toggleFilter(state){
            this.$emit("toggle",state)
        },
        clearAllCompleted(){
            this.$emit("clearAll")
        }
    }
}
</script>

<style lang="stylus" scoped>
.helper{
    position:relative;
    background:#fff;
    line-height:3em;
    border: 1px solid #999;
    border-top:none;
    font-size:13px;
    color:#000;
}
.left{
    padding:0 10px 0 10px;
}
.tabs{
    padding: 0 10px 0 100px;
}
.state{
    margin:0 5px 0 5px;
    padding:4px;
    cursor:pointer;
}
.actives{
    border:1px solid #999;
    box-shadow:0 0 1px 1px #eee;
    border-radius:5px;
}
.clear{
    position:relative;
    float:right;
    margin:0 10px 0 0;
    cursor:pointer;
}
</style>