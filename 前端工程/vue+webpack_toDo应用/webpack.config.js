const path=require('path');
const HTMLPlugin=require('html-webpack-plugin');
const webpack=require('webpack');
const VueLoaderPlugin = require('vue-loader/lib/plugin');
const ExtractPlugin = require('extract-text-webpack-plugin');
//判断是开发环境还是生产环境，在json文件中写了，使用cross-env
//NODE_ENV=production是生产环境
//NODE_ENV=development是开发环境
const isDev = process.env.NODE_ENV === 'development';
const config = {
    target: 'web',
    entry:path.join(__dirname,'src/index.js'),
    output:{
        //开发环境
        filename:'bundle.[hash:8].js',
        path:path.join(__dirname,'dist')
    },
    module: {
        rules: [
            {
                test:/\.vue$/,
                loader:'vue-loader'
            },
            {
                test:/\.jsx$/,
                loader:'babel-loader'
            },
            
            {
                test:/\.(gif|jpg|png|svg)$/,
                use: [
                 {
                    loader: 'url-loader',
                    options:{
                        limit:1024,
                        name:'[name]-aaa.[ext]'
                    }
                 }
                ]
            }
        ]
    },
    //配置HTMLPlugin 安装npm i html-webpack-plugin包，为了方便集成html
    plugins:[
        new VueLoaderPlugin(),
        //如果页面使用vue等前端框架，一定要加的配置
        new webpack.DefinePlugin({
            //判断环境
            'process.env':{
                NODE_ENV:isDev ? '"development"' : '"production"'
            }
        }),
        new HTMLPlugin()
    ]
}
//判断是开发环境还是生产环境，在json文件中写了，使用cross-env
//NODE_ENV=production是生产环境
//NODE_ENV=development是开发环境
if (isDev) {
    config.module.rules.push({
        //预处理器stylus,所有需要的包都是这么配置的
            test:/.\.styl/,
            use:[
                'style-loader',
                'css-loader',
                {
                    loader: 'postcss-loader',
                    options: {
                        sourceMap: true,
                    }
                },
                'stylus-loader'
            ]
        })
    //为在浏览器调试代码时重新映射代码，是代码可读，方便定位错误
    config.devtool = '#cheap-module-eval-source-map',
    config.devServer = {
        //端口
        port: 8000,
        //ip一般设为0.0.0.0，因为这样不光可以用本机ip访问页面，也可以用内网ip
        host:'0.0.0.0',
        //webpack-dev-server运行过程中出现任何错误都显示在网页上，方便调试
        overlay:{
            errors:true
        },
        //修改组件代码，只刷新组件部分，可使页面的内容数据留着
        hot: true
    }
    config.plugins.push(
        new webpack.HotModuleReplacementPlugin(),
        new webpack.NoEmitOnErrorsPlugin()
    )
}
else{
    config.entry = {
        app:path.join(__dirname,'src/index.js'),
        vendor:["vue"]
    }
    config.output.filename = '[name].[chunkhash:8].js'
    config.module.rules.push(
       //预处理器stylus,所有需要的包都是这么配置的
       {
        test:/.\.styl/,
        use:ExtractPlugin.extract({
            fallback: 'style-loader',
            use:[
                'css-loader',
                {                        
                    loader: 'postcss-loader',
                    options: {
                        sourceMap: true,
                    }
                },
                'stylus-loader'
                ]
            })
        },
    )
    config.plugins.push(
        new ExtractPlugin('styles.[md5:contentHash:hex:8].css'),
    )
    // 为了把框架文件单独导出

    config.optimization = {
        splitChunks: {
            cacheGroups: {
                vendor: {
                    name: "vendor",
                    chunks: "initial"
                },
                runtime:{
                    name:"runtime",
                    chunks:"initial"
                }
            }
        },
        runtimeChunk: true
    }
}
module.exports = config;