package br.ufscar.dc.dsw;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/ServletC"})
public class ServletC extends HttpServlet {

  private static final long serialVersionUID = 1L;

	protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        out.println("<html>");
          out.println("<head>");
          out.println("<title>Servlet ServletC</title>");
          out.println("</head>");
          out.println("<body>");
        Integer i = (Integer) request.getAttribute("valor");
        if (i == null) {
          i = 0;
        }
        i = i + 1000;
        request.setAttribute("valor", i);
        out.println("Conteúdo gerado no ServletC: Valor = " + i + "<br/>");
        out.println("</body>");
        out.println("</html>");
  }

  @Override
  protected void doGet(HttpServletRequest request, HttpServletResponse response)
          throws ServletException, IOException {
      processRequest(request, response);
  }

  @Override
  protected void doPost(HttpServletRequest request, HttpServletResponse response)
          throws ServletException, IOException {
      processRequest(request, response);
  }
}