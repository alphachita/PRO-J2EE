import { Component, Sanitizer } from '@angular/core';
import Post from './post.modal';
import { DomSanitizer } from '@angular/platform-browser';
import { post } from 'selenium-webdriver/http';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'practice';

  public post: Post;
  public postList: Post[];

  public constructor(private sanitizer:DomSanitizer){

    this.post=new Post();
    this.postList= [];
  }

  public postText(){
    this.postList.splice(0,0,this.post);
    //re initialize
    this.post = new Post();
  }

  public likeCount(item:Post){
    item.likeCount += 1;
  }

  public subscribeCount(item:Post){
    item.subscribeCount += 1;
  }

  public addCommment(item:Post){
    this.postComment(item);
  }

  public postComment(item:Post){
    console.log("hii");
    item.commentList.splice(0,0,this.post.postComment);
    this.post = new Post();
  }

  public deletePost(itemIndex){
     this.postList.splice(itemIndex,1);
  }

  public deleteComment(comIndex,item:Post){
    console.log("hiii");
    item.commentList.splice(comIndex,1);
    
  }

  public postImage(event){
    const refElement=event.target;
    const uploadFile=refElement.files[0];

    let uploadFileasURL=URL.createObjectURL(uploadFile);
    const uploadFileasURLNew=this.sanitizer.bypassSecurityTrustResourceUrl(uploadFileasURL);

    this.post.postType = 'IMAGE';
    this.post.postValue = uploadFileasURLNew;

    this.postList.splice(0,0,this.post);

    this.post = new Post();
  }
}
