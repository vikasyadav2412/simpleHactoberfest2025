$(document).ready(function() {
    const successMessage = $('#success-message');
  
    $('#task-form').submit(function(event) {
      event.preventDefault();
  
      const title = $('#title').val();
      const description = $('#description').val();
      const dueDate = $('#due-date').val();
  
      // Simulate adding task (you can replace this with your actual API call)
      setTimeout(function() {
        // Create table cells for each information
        const titleCell = $('<td>').text(title).css({
          'background-color': 'lightgreen',
          'border': '1px solid black',
          'padding': '5px'
        });
        const descriptionCell = $('<td>').text(description).css({
          'background-color': 'lightgreen',
          'border': '1px solid black',
          'padding': '5px'
        });
        const dueDateCell = $('<td>').text(dueDate).css({
          'background-color': 'lightgreen',
          'border': '1px solid black',
          'padding': '5px'
        });
  
        // Create a new table row and append cells
        const newRow = $('<tr>').append(titleCell, descriptionCell, dueDateCell);
  
        // Append the row to the table body
        $('#task-list').append(newRow);
  
        // Animate the new row
        newRow.hide().fadeIn(500); // Adjust the duration as needed
  
        // Show success message
        successMessage.text("Successfully added");
        successMessage.show();
  
        // Hide success message after 3 seconds
        setTimeout(function() {
          successMessage.hide();
        }, 3000);
  
        // Clear form inputs
        $('#title').val('');
        $('#description').val('');
        $('#due-date').val('');
      }, 1000); // Simulate a delay for demonstration
    });
  });
  