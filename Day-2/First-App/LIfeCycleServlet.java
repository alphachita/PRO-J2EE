package serv1;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/life_cycle")
public class LIfeCycleServlet extends HttpServlet {
	@Override
	public void init() throws ServletException {
		System.out.println("init() called =========");
	}
	
	@Override
	protected void service(HttpServletRequest arg0, HttpServletResponse arg1) throws ServletException, IOException {
		System.out.println("service() called ============");
	}
	
	@Override
	public void destroy() {
		System.out.println("destroy() called ================");
	}
	
}
