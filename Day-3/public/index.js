const channelID = 2992785;
const url = 'https://api.thingspeak.com/channels/2992785/feeds.json?results=2';

async function fetchData() {
    try {
        const response = await fetch(url);
        const data = await response.json();
        const feed = data.feeds[0];
        soli1d1 = Number(feed.field1);
        soli2d1 = Number(feed.field2);

        const display = `
            <p class="text-xl font-semibold mb-4 text-black-900">Temperature: ${soli1d1}</p>
            <p class="text-xl font-semibold mb-4 text-black-900">Humidity: ${soli2d1}</p>
            <p class="text-xl font-semibold mb-4 text-black-900">Time: ${new Date(feed.created_at).toLocaleString()}</p>
        `;


        document.getElementById('thingspakdata').innerHTML = display;
    }
    catch (erroe) {
        console.error('Error fetching data: ', error);
    }
}
fetchData()
setInterval(fetchData,1000)