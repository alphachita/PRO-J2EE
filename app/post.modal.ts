export default class Post{
        public postType;
        public postValue;
        public postComment;

        public likeCount;
        public subscribeCount;
        public commentList: any[];

        public constructor() {

                this.commentList= [];
                this.likeCount=0;
                this.postComment='';
                this.postType='TEXT';
                this.postValue='';
                this.subscribeCount=0;

        }



}